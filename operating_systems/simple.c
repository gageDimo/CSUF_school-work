/**
 * simple.c
 * A simple kernel module.
 * To compile, run makefile by entering "make"
 * Operating System Concepts - 10th Edition
 * Copyright John Wiley & Sons - 2018
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>

typedef struct list_head list_head;
typedef struct birthday birthday;
struct birthday { int year; int month; int day; list_head list; }
static LIST_HEAD(birthday_list);

birthday* birthday_create(int year, int month, int day) {
    birthday* person = kmalloc(sizeof(*person), GFP_KERNEL);
	person->year = year;  person->month = month;  person->day = day;
	INIT_LIST_HEAD(&person->list);  return person; }

void birthday_delete(birthday* pb) { kfree(pb); }

void birthday_print(birthday* pb) { printk(KERN_INFO "birthday(yr=%04d, mon=%02d, day=%02d)\n",
                                           pb->year, pb->month, pb->day); }

void list_add_birthday(int year, int month, int day) {
    birthday* pb = birthday_create(year, month, day);  list_add_tail(&pb->list, &birthday_list); }

void birthday_list_init(void) {
	list_add_birthday(1950,  3,  1);
	list_add_birthday(1960,  5,  3);
	list_add_birthday(1970,  7,  5);
	list_add_birthday(1980,  9,  3);
	list_add_birthday(1990, 10, 31);
}

void birthday_list_traverse(void) {
	birthday *p, *next;
	list_for_each_entry_safe(p, next, &birthday_list, list) {
	    birthday_print(p);
		list_del(&p->list);
		birthday_delete(p);
	}
}


/* This function is called when the module is loaded. */
int simple_init(void) { printk(KERN_INFO "Loading Module\n");  birthday_list_init();  return 0; }

/* This function is called when the module is removed. */
void simple_exit(void) { birthday_list_traverse();  printk(KERN_INFO "Removing Module\n"); }

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");
