//
//  memmgr.c
//  memmgr
//
//  Created by William McCarthy on 17/11/20.
//  Copyright © 2020 William McCarthy. All rights reserved.
//

// Gage Dimapindan, CWID: 888017746
// Virtual Memory Manager Project (CPSC 351)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <alloca.h>
#include <unistd.h>

#define ARGC_ERROR 1
#define FILE_ERROR 2
#define BUFLEN 256
#define FRAME_SIZE 256
#define TOTAL_FRAMES 256
#define TLB_SIZE 16
#define PAGE_SIZE 256

//-------------------------------------------------------------------
unsigned getpage(unsigned x) { return (0xff00 & x) >> 8; }

unsigned getoffset(unsigned x) { return (0xff & x); }

void getpage_offset(unsigned x) {
  unsigned  page   = getpage(x);
  unsigned  offset = getoffset(x);
  printf("x is: %u, page: %u, offset: %u, address: %u, paddress: %u\n", x, page, offset,
         (page << 8) | getoffset(x), page * 256 + offset);
}

int pgTbl[PAGE_SIZE];       // page table to hold page numbers
int pgFrames[PAGE_SIZE];    // page table to hold frame numbers
int pgFaults = 0;           // page faults

int TLBtable[TLB_SIZE][2];  // TLB table
int TLBHits = 0;            // amount of TLB hits
int TLB_num_entry = 0;      // tracks amount of entries in the TLB

int phys_mem[TOTAL_FRAMES][FRAME_SIZE];   // physical memor as 2D array

int first_open_frame = 0;   // tracks the first available frame
int first_open_pgTblIdx = 0;    // tracks the first available page table entry

signed char bs_buff[BUFLEN];    // buffer containing reads from BACKING_STORE.bin
signed char byte_val;           // byte value in memory

FILE *fBS;

// inserts a page num and frame num into TLB with FIFO replacement
void addToTLB(int page, int frame) {

  int index; // if already in TLB, break
  for (index = 0; index < TLB_num_entry; index++) {
    if (TLBtable[index][1] == page) {
      break;
    }
  }

  // checks if num of entries is equal to index
  if (index == TLB_num_entry) {
    if (TLB_num_entry < TLB_SIZE) {
      TLBtable[TLB_num_entry][1] = page;
      TLBtable[TLB_num_entry][2] = frame;
    }
    else {
      for (index = 0; index = TLB_SIZE - index; index++) {
        TLBtable[index][1] = TLBtable[index+1][1];
        TLBtable[index][2] = TLBtable[index+1][2];
      }
      TLBtable[TLB_num_entry-1][1] = page;
      TLBtable[TLB_num_entry-1][2] = frame;
    }
  }
  else { // if index is not equal to number of TLB entries
    for (index = index; index < TLB_num_entry - 1; index++) {
      TLBtable[index][1] = TLBtable[index+1][1];
      TLBtable[index][2] = TLBtable[index+1][2];
    }
    if (TLB_num_entry < TLB_SIZE) {
      TLBtable[TLB_num_entry][1] = page;
      TLBtable[TLB_num_entry][2] = frame;
    }
    else {
      TLBtable[TLB_num_entry-1][1] = page;
      TLBtable[TLB_num_entry-1][2] = frame;
    }
  }
  if (TLB_num_entry < TLB_SIZE) {
    TLB_num_entry = TLB_num_entry + 1;
  }
}

// reads BACKING_STORE.bin and brings frame into physical memory and page table
void readBSFile(int page) {
  // seeks to byte BUFLEN in fBS pointer
  if (fseek(fBS, page * BUFLEN, SEEK_SET) != 0) {
    fprintf(stderr, "Error: can't seek from file\n");
  }
  if (fread(bs_buff, sizeof(signed char), BUFLEN, fBS) == 0) {
    fprintf(stderr, "Error: can't read from file\n");
  }

  // load bits into first available frame in physical memory array
  for (int i = 0; i < BUFLEN; i++) {
    phys_mem[first_open_frame][i] = bs_buff[i];
  }

  // load frame num into page table in the first available frame
  pgTbl[first_open_pgTblIdx] = page;
  pgFrames[first_open_pgTblIdx] = first_open_frame;

  first_open_frame++;
  first_open_pgTblIdx++;

}

// takes logical address and obtains physical address and its value stored there
void getPageNums(unsigned log_add) {
  // get page number and offset from logical address; transform to int
  int page = getpage((int)log_add);
  int offset = getoffset((int)log_add);

  int frame_num = -1; // initialized to -1 to ensure validation of conditions

  // search through TLB for a match
  for (int i = 0; i < TLB_SIZE; i++) {
    if (TLBtable[i][1] == page) {
      TLBtable[i][2] = TLBtable[i][1];
      TLBHits = TLBHits + 1;  // increment if frame num is extracted
    }
  }

  // checks if frame num wasn't found
  if (frame_num == -1) {
    for (int i = 0; i < first_open_pgTblIdx; i++) {
      if (pgTbl[i] == page) {
        frame_num = pgFrames[i];  // extract frame num from page table if found there
      }
    }
    if (frame_num == -1) {
      readBSFile(page);   // page fault; calls function to get frame into physical memory and page table
      pgFaults++;
      frame_num = first_open_frame - 1;   // sets frame num to current first available frame
    }
  }

  addToTLB(page,frame_num);   // calls function to insert page and frame num into TLB
  byte_val = phys_mem[frame_num][offset];   // frame num and offset used to get signed value stored in address
  printf("frame number: %d\n", frame_num);
  // produce output of contents
  printf("Virtual address: %d Physical address: %d Value: %d\n", log_add, (frame_num << 8) | offset, byte_val);

}

int main(int argc, const char* argv[]) {
  FILE* fadd = fopen("addresses.txt", "r");    // open file addresses.txt  (contains the logical addresses)
  if (fadd == NULL) { fprintf(stderr, "Could not open file: 'addresses.txt'\n");  exit(FILE_ERROR);  }

  FILE* fcorr = fopen("correct.txt", "r");     // contains the logical and physical address, and its value
  if (fcorr == NULL) { fprintf(stderr, "Could not open file: 'correct.txt'\n");  exit(FILE_ERROR);  }

  char buf[BUFLEN];
  unsigned   page, offset, physical_add, frame = 0;
  unsigned   logic_add;                  // read from file address.txt
  unsigned   virt_add, phys_add, value;  // read from file correct.txt

  // opens BACKING_STORE.bin
  fBS = fopen("BACKING_STORE.bin", "rb");
  if (fBS == NULL) {
    fprintf(stderr, "Could not open file: 'BACKING_STORE.bin'\n");
    exit(FILE_ERROR);
  }

  // printf("ONLY READ FIRST 20 entries -- TODO: change to read all entries\n\n");
  printf("READ ALL ENTRIES\n\n");

  // not quite correct -- should search page table before creating a new entry
      //   e.g., address # 25 from addresses.txt will fail the assertion
      // TODO:  add page table code
      // TODO:  add TLB code
      // check line 57 for TLB code and 102 for page table code

      int trans_adds = 0;

  while (frame < FRAME_SIZE) {

    fscanf(fcorr, "%s %s %d %s %s %d %s %d", buf, buf, &virt_add,
           buf, buf, &phys_add, buf, &value);  // read from file correct.txt

    fscanf(fadd, "%d", &logic_add);  // read from file address.txt
    page   = getpage(  logic_add);
    offset = getoffset(logic_add);

    physical_add = frame++ * FRAME_SIZE + offset;

    assert(physical_add == phys_add);

    // todo: read BACKING_STORE and confirm value matches read value from correct.txt
    getPageNums(logic_add);
    trans_adds++;

    printf("logical: %5u (page: %3u, offset: %3u) ---> physical: %5u -- passed\n", logic_add, page, offset, physical_add);
    if (frame % 5 == 0) { printf("\n"); }
  }

  // printf("ONLY READ FIRST 20 entries -- TODO: change to read all entries\n\n");
    printf("READ ALL ENTRIES\n\n");

  // printf("ALL logical ---> physical assertions PASSED!\n");
  // printf("!!! This doesn't work passed entry 24 in correct.txt, because of a duplicate page table entry\n");
  // printf("--- you have to implement the PTE and TLB part of this code\n");

  printf("Number of translated addresses = %d\n", trans_adds);
  double PFrate = pgFaults/(double)trans_adds;
  double TLBrate = TLBHits/(double)trans_adds;

  printf("Page Faults = %d\n", pgFaults);
  printf("Page Fault Rate = %.3f\n", PFrate);
  printf("TLB Hits = %d\n", TLBHits);
  printf("TLB Hit Rate = %.3f\n", TLBrate);

//  printf("NOT CORRECT -- ONLY READ FIRST 20 ENTRIES... TODO: MAKE IT READ ALL ENTRIES\n");
  fclose(fcorr);
  fclose(fadd);
  fclose(fBS);

  printf("\n\t\t...done.\n");
  return 0;
}
