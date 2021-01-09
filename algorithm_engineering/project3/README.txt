Project 3: Balloon Juice (Fall 2020)
CPSC 335-02

<team name and list of members>

Team Megabyte

Kien Truong
ktruong29@csu.fullerton.edu
CWID: 898165535

Gage Dimapindan
mdimapindan@csu.fullerton.edu
CWID: 888017746

Brian Lucero
13rianlucero@csu.fullerton.edu
CWID:

<intro>

Our project uses a BFS (breath first search) to reach the Mystic Balloon, a node that is
supposed to be deep within a network of nodes. At a starting point, the pointer to which
we search through the plot keeps track of the depth of the entire thing and when it
reaches the Mystic Balloon, it will report the plot's depth. We also implemented
visualizations to show each step of how far the pointer travels.

<contents>

- README.txt: the file you are currently reading
- index-js-p5-example.html: open this file with any web browser to run the file
- p5.js: this is the P5 package; it's loaded in the html
- p5.play.js: functions as a sprite kit for the images
- cs-sketch.js: contains P5 user-defined linkage functions as well as support functions
- assets:
   > draw-stuff.js: loads a JavaScript file from a folder other than the index HTML file's
	folder location; includes the utility draw_grid function written in P5+JS
   > styles.css: an extra small sample of controlling webpage styling
- 335-02-Complexity_Order_Megabyte.pdf: a pdf file that contains our time complexity for
  the project's algorithm
- balloon.js: a constructor/pseudo-header file that contains values for each integer
- balloonjuice.js: the main file where the functions take place; contains the algos to
     search and link nodes together and display the depth at where the MB is reached
- green_balloon.png: the model for which we designed our balloons off of
- balloonAnimation-HelperCode.txt - self-explanatory, helps animate the code

<setup and installation>

1) extract the .zip file into a folder
2) double-click on the index-js-p5-example.html file or right-click and open with any web
	browser; you should see the process in which the pointer travels and links
	the balloons

<bugs>
none
