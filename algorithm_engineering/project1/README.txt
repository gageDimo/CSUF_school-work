Project 1: Cella Ant #x15 (Fall 2020)
CPSC 335-02

<team name and list of members>

Team Megabyte

Kien Truong
ktruong29@csu.fullerton.edu
CWID: 898165535

Zach Sarvas
zsarvas@csu.fullerton.edu
CWID: 888927977

Gage Dimapindan
mdimapindan@csu.fullerton.edu
CWID: 888017746

Vincent Nguyen
nguyenvincent@csu.fullerton.edu
CWID: 890439656

<intro>

Our project draws a 41x41 square grid and runs an invisible "ant" (known as bot) from cell
to cell and changes the color of each grid it passes. The program should run for about 1,000
moves and shows the grid change after each move.

The project uses HTML, JavaScript and P5.js, a JS=adapted version of the Processing Language.
The P5 file provides automated animation and GUI manipulation functions that are simpler than
JavaScript.

<contents>

- README.txt: the file you are currently reading
- index-js-p5-example.html: open this file with any web browser to run the file
- p5.js: this is the P5 package; it's loaded in the html
- cs-sketch.js: contains P5 user-defined linkage functions as well as support functions
- assets:
   > draw-stuff.js: loads a JavaScript file from a folder other than the index HTML file's
	folder location; includes the utility draw_grid function written in P5+JS
   > styles.css: an extra small sample of controlling webpage styling
- 335-02-Complexity_Order_Megabyte.pdf: a pdf file that contains our time complexity for
  the project's algorithm

<setup and installation>

1) extract the .zip file into a folder
2) double-click on the index-js-p5-example.html file or right-click and open with any web
	browser; you should see a 41x41 grid with many of the cells in a different color

<bugs>

The colors of the grid appear all at once rather than one at a time.
