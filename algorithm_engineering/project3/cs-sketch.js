
// Make global g_canvas JS 'object': a key-value 'dictionary'.
// var g_canvas = { cell_size:20, wid:41, hgt:41 }; // JS Global var, w canvas size info.
// var g_frame_cnt = 0; // Setup a P5 display-frame counter, to do anim
// var g_frame_mod = 1; // Update ever 'mod' frames.
// var g_stop = 0; // Go by default.

var g_canvas = {cell_size:20, wid:100, hgt:65 }; // JS Global var, w canvas size info.
var index = 0;  //For output the path to balloon juice
let x = 190;
let y = 90;
let balloon = new BalloonJuiceSearch(10,4,5);
balloon.searchBalloon(3,13,3);
length = balloon.path.length - 1;
var atDepth = balloon.path[length].depth;
var string = "Found at depth: " + atDepth;

//This function happens ONCE ONLY
function setup(){
  let sz = g_canvas.cell_size;
  let width = sz * g_canvas.wid;  // Our 'canvas' uses cells of given size, not 1x1 pixels.
  let height = sz * g_canvas.hgt;
  createCanvas(width, height );  // Make a P5 canvas.
  // draw_grid( 20, 20, 'white', 'yellow' ); //draw line in white and text in yellow
  frameRate(1);
  fill('blue');
  textSize(32);
  strokeWeight(4);
  stroke(255, 204, 0);
}

// Brian's code to animate the balloons
// note: put this function into the draw() function later

// general idea:
// balloon is animated in a separate app, MS paint.
// load the .png image into the p5 script
// use the .png image of a "green" balloon to animate the various balloons that we have
// -------------------------------------


function draw_balloon(x_coordinate, y_coordinate)
{
  // code to animate the green balloon
  ellipse(x_coordinate, y_coordinate, 200, 100);
}

function draw_line(x_coordinate, y_coordinate)
{
  var x_l = x_coordinate + 150;
  var y_l = y_coordinate + 60;

  line(x_coordinate, y_coordinate + 50, x_l, y_l);
}

//Order matters
//function draw() is a loop -> execute multiple times
function draw()
{
  if(index < balloon.path.length)
  {
    var balloonPath = balloon.path[index];

    draw_balloon(x, y);
    if(index != balloon.path.length -1)
    {
        draw_line(x,y);
    }

    fill('red');

    text(balloonPath, x - 50, y);
    index = index + 1;
    x = x + 190;
    y = y + 100;
  }
  else if(index == balloon.path.length)
  {
    text(string, x - 250, y);
  }

}
