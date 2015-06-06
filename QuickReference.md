

# Introduction #
You will find below a short (and I mean _short_) summary of the functions and variables
defined by cprocessing. Each entry contains a Processing feature
with a link to the reference page of that feature in the Processing site, the cprocessing equivalent, if any, and a brief description of that feature.

As a rule, cprocessing functions have exactly the same name of their Processing counterparts, and allow the same argument variations.

This is still incomplete! Browsing the examples in the repository
will give you a more up-to-date picture of cprocessing's features.

# Structure #

<table cellpadding='2' border='0' cellspacing='0' width='600px'>
<tbody>
<blockquote><tr>
<blockquote><td width='100'><b>Processing</b> </td>
<td width='100'><b>cprocessing</b></td>
<td width='400'><b>Description</b></td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/draw_.html'>draw()</a></td>
<td> <code>draw()</code></td>
<td> a function of your program that is called for drawing<br>
a frame</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/exit_.html'>exit()</a></td>
<td> <code>N/A</code></td>
<td> exits the application</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/loop_.html'>loop()</a></td>
<td> <code>N/A</code></td>
<td> makes <code>draw()</code> be called periodically</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/noLoop_.html'>noLoop()</a></td>
<td> <code>N/A</code></td>
<td> stops <code>draw()</code> fro being called periodically</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/popStyle_.html'>popStyle()</a></td>
<td> <code>N/A</code></td>
<td> restores the prior style settings</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/pushStyle_.html'>pushStyle()</a></td>
<td> <code>N/A</code></td>
<td> saves the current style settings</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/redraw_.html'>redraw()</a></td>
<td> <code>redraw()</code></td>
<td> Executes the code within draw()</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/setup_.html'>setup()</a></td>
<td> <code>setup()</code></td>
<td> a function of your program that is called<br>
automatically once by run()</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/size_.html'>size()</a></td>
<td> <code>size()</code></td>
<td> used to establish the dimensions of the drawing window</td>
</blockquote></tr>
</blockquote><blockquote></tbody>
</table>
<br></blockquote>

<h1>Environment</h1>

<table cellpadding='2' border='0' cellspacing='0' width='600px'>
<blockquote><tr>
<blockquote><td width='100'><b>Processing</b> </td>
<td width='100'><b>cprocessing</b></td>
<td width='400'><b>Description</b></td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/cursor_.html'>cursor()</a></td>
<td><code>N/A</code></td>
<td>Changes or shows the mouse cursor.</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://processing.org/reference/delay_.html'>delay()</a></td>
<td><code>N/A</code></td>
<td> stops the program from running for a specified time</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://processing.org/reference/day_.html'>day()</a></td>
<td><code>N/A</code></td>
<td> returns the value of the current day</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/focused.html'>focused</a></td>
<td><code>N/A</code></td>
<td></td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/frameCount.html'> frameCount</a></td>
<td><code>N/A</code></td>
<td>Number of frames drawn so far.</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/frameRate_.html'>frameRate()</a></td>
<td><code>N/A</code></td>
<td>Sets the number of times <code>draw()</code> will be called per second.</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/frameRate.html'>frameRate</a></td>
<td><code>framerate</code></td>
<td>Estimated number of frames per second for the recent past.</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/height.html'>height</a></td>
<td><code>height</code></td>
<td>Height of the drawing window in pixels.</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://processing.org/reference/hour_.html'>hour()</a></td>
<td><code>N/A</code></td>
<td> returns the value of the current hour</td>
</blockquote></tr></blockquote>

<blockquote><tr>
<blockquote><td><a href='http://processing.org/reference/link_.html'>link()</a></td>
<td><code>N/A</code></td>
<td> links to a webpage</td>
</blockquote></tr></blockquote>

<blockquote><tr>
<blockquote><td><a href='http://processing.org/reference/millis_.html'>millis()</a></td>
<td><code>N/A</code></td>
<td> returns the amount of milliseconds since starting a program</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://processing.org/reference/minute_.html'>minute()</a></td>
<td><code>N/A</code></td>
<td> returns the value of the current minute</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://processing.org/reference/month_.html'>month()</a></td>
<td><code>N/A</code></td>
<td> returns the value of the current month</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/noCursor_.html'>noCursor()</a></td>
<td><code>N/A</code></td>
<td>Inhibits the display of the mouse cursor.</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/online.html'>online</a></td>
<td><code>N/A</code></td>
<td></td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/screen.html'>screen</a></td>
<td><code>N/A</code></td>
<td>holds the width, height and pixels of the display.</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://processing.org/reference/second_.html'>second()</a></td>
<td><code>N/A</code></td>
<td> returns the value of the current second</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://processing.org/reference/year_.html'>year()</a></td>
<td><code>N/A</code></td>
<td> returns the value of the current year</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/width.html'>width</a></td>
<td><code>width</code></td>
<td>width of the drawing window in pixels</td>
</blockquote></tr>
</table>
<br></blockquote>

<h1>Color</h1>
<h2><i>Setting</i></h2>
<table cellpadding='2' border='0' cellspacing='0' width='600px'>
<blockquote><tbody>
<blockquote><tr>
<blockquote><td width='100'><b>Processing</b> </td>
<td width='100'><b>cprocessing</b></td>
<td width='400'><b>Description</b></td>
</blockquote></blockquote><blockquote></tr></blockquote></blockquote>

<blockquote><tr>
<blockquote><td><a href='http://www.processing.org/reference/background_.html'>background()</a></td>
<td> <code>background()</code></td>
<td> clears the drawing with a background color</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/colorMode_.html'>colorMode()</a></td>
<td> <code>colorMode()</code></td>
<td> sets up the color system (RGB or HSB) for specifying<br>
colors</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/fill_.html'>fill()</a></td>
<td> <code>fill()</code></td>
<td> specifies the color for drawing filled shapes</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/noFill_.html'>noFill()</a></td>
<td> <code>noFill()</code></td>
<td> makes shapes be rendered non-filled</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/noStroke_.html'>noStroke()</a></td>
<td> <code>noStroke()</code></td>
<td> makes shapes be rendered without their borders</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/stroke_.html'>stroke()</a></td>
<td> <code>stroke()</code></td>
<td> specifies the color for drawing lines and shape borders</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/noTint_.html'>noTint()</a></td>
<td> <code>N/A</code></td>
<td> reverts to displaying images with their original values</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/tint_.html'>tint()</a></td>
<td> <code>N/A</code></td>
<td> sets the fill value for displaying images</td>
</blockquote></tr>
</blockquote><blockquote></tbody>
</table>
<h2><i>Creating & Reading</i></h2>
<table cellpadding='2' border='0' cellspacing='0' width='600px'>
</blockquote><blockquote><tbody>
<blockquote><tr>
<blockquote><td width='100'><b>Processing</b> </td>
<td width='100'><b>cprocessing</b></td>
<td width='400'><b>Description</b></td>
</blockquote></blockquote><blockquote></tr>
<blockquote><tr>
<blockquote><td><a href='http://www.processing.org/reference/alpha_.html'>alpha()</a></td>
<td> <code>alpha()</code></td>
<td> returns the alpha (transparency) component of a color</td>
</blockquote></blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/blendColor_.html'>blendColor()</a></td>
<td> <code>N/A</code></td>
<td> returns the blending between two colors</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/blue_.html'>blue()</a></td>
<td> <code>blue()</code></td>
<td> returns the blue component of a color</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/brightness_.html'>brightness()</a></td>
<td><code>brightness()</code></td>
<td> returns the brightness of a color</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/color_.html'>color()</a></td>
<td> <code>color()</code></td>
<td> builds a color value from its components</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/green_.html'>green()</a></td>
<td><code>green()</code></td>
<td> returns the green component of a color</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/hue_.html'>hue()</a></td>
<td> <code>hue()</code></td>
<td> returns the hue of a color</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/lerpColor_.html'>lerpColor()</a></td>
<td> <code>N/A</code></td>
<td> returns a linear interpolation between two colors</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/red_.html'>red()</a></td>
<td> <code>red()</code></td>
<td> returns the red component of a color</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/saturation_.html'>saturation()</a></td>
<td> <code>saturation()</code></td>
<td> returns the saturation of a color</td>
</blockquote></tr>
</blockquote><blockquote></tbody>
</table>
<br></blockquote></blockquote>

<h1>Shape</h1>
<h2><i>2D Primitives</i></h2>

<table cellpadding='2' border='0' cellspacing='0' width='600px'>
<blockquote><tr>
<blockquote><td width='100'><b>Processing</b> </td>
<td width='100'><b>cprocessing</b></td>
<td width='400'><b>Description</b></td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/arc_.html'>arc()</a></td>
<td><code>N/A</code></td>
<td>draws an arc of ellipse</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/ellipse_.html'>ellipse()</a></td>
<td><code>ellipse()</code></td>
<td>draws an ellipse</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/line_.html'>line()</a></td>
<td><code>line()</code></td>
<td>draws a line segment</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/point_.html'>point()</a></td>
<td><code>point()</code></td>
<td>draws a point</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/quad_.html'>quad()</a></td>
<td><code>quad()</code></td>
<td>draws a quadrilateral</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/rect_.html'>rect()</a></td>
<td><code>N/A</code></td>
<td>draws a rectangle</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/triangle_.html'>triangle()</a></td>
<td><code>triangle()</code></td>
<td>draws a triangle</td>
</blockquote></tr>
</table></blockquote>

<h2><i>3D Primitives</i></h2>
<table cellpadding='2' border='0' cellspacing='0' width='600px'>
<tbody>
<blockquote><tr>
<blockquote><td width='100'><b>Processing</b> </td>
<td width='100'><b>cprocessing</b></td>
<td width='400'><b>Description</b></td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/box_.html'>box()</a></td>
<td><code>box()</code></td>
<td>draws a parallelepiped</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/sphere_.html'>sphere()</a></td>
<td><code>sphere()</code></td>
<td>draws a sphere</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/sphereDetail_.html'>sphereDetail()</a></td>
<td><code>sphereDetail()</code></td>
<td>sets the level of detail used to render spheres</td>
</blockquote></tr>
</blockquote><blockquote></tbody>
</table></blockquote>

<h2><i>Curves</i></h2>

<table cellpadding='2' border='0' cellspacing='0' width='600px'>
<blockquote><tr>
<blockquote><td width='100'><b>Processing</b> </td>
<td width='100'><b>cprocessing</b></td>
<td width='400'><b>Description</b></td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/bezier_.html'>bezier()</a></td>
<td><code>bezier()</code></td>
<td> Draws a cubic Bézier curve</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/bezierDetail_.html'>bezierDetail()</a></td>
<td><code>bezierDetail()</code></td>
<td> Changes sampling rate of Bézier curves</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/bezierPoint_.html'>bezierPoint()</a></td>
<td><code>bezierPoint()</code></td>
<td> Evaluates one coordinate of a point on a Bézier curve</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/bezierTangent_.html'>bezierTangent()</a></td>
<td><code>bezierTangent()</code></td>
<td> Evaluates one coordinate of a tangent of a Bézier curve</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/curve_.html'>curve()</a></td>
<td><code>N/A</code></td>
<td> Draws a cubic Catmull-Rom curve</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/curveDetail_.html'>curveDetail()</a></td>
<td><code>N/A</code></td>
<td> Changes the sampling rate of Catmull-Rom curves</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/curvePoint_.html'>curvePoint()</a></td>
<td><code>N/A</code></td>
<td> Evaluates one coordinate of a point of<br>
a Catmull-Rom curve</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/curveTangent_.html'>curveTangent()</a></td>
<td><code>N/A</code></td>
<td> Evaluates one coordinate of a tangent of<br>
a Catmull-Rom curve</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/curveTightness_.html'>curveTightness()</a>
</td>
<td> <code>N/A</code></td>
<td> Changes the tightness of Catmull-Rom curves</td>
</blockquote></tr>
</table></blockquote>

<h2><i>Attributes</i></h2>
<table cellpadding='2' border='0' cellspacing='0' width='600px'>
<tbody>
<blockquote><tr>
<blockquote><td width='100'><b>Processing</b> </td>
<td width='100'><b>cprocessing</b></td>
<td width='400'><b>Description</b></td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/noSmooth_.html'>noSmooth()</a></td>
<td> <code>noSmooth()</code></td>
<td>renders in non-antialiased mode</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/rectMode_.html'>rectMode()</a></td>
<td> <code>N/A</code></td>
<td> changes the semantics of the arguments of <code>rect()</code></td>
</blockquote></tr></blockquote>

<blockquote><tr>
<blockquote><td><a href='http://www.processing.org/reference/ellipseMode_.html'>ellipseMode()</a></td>
<td> <code>ellipseMode()</code></td>
<td> changes the semantics of the arguments of <code>ellipse()</code></td>
</blockquote></tr></blockquote>


<blockquote><tr>
<blockquote><td><a href='http://www.processing.org/reference/smooth_.html'>smooth()</a></td>
<td> <code>smooth()</code></td>
<td> renders in antialiased mode</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/strokeCap_.html'>strokeCap()</a></td>
<td> <code>N/A</code></td>
<td></td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/strokeJoin_.html'>strokeJoin()</a></td>
<td><code>N/A</code></td>
<td></td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/strokeWeight_.html'>strokeWeight()</a></td>
<td><code>strokeWeight()</code></td>
<td>changes the thickness of lines</td>
</blockquote></tr>
</blockquote><blockquote></tbody>
</table></blockquote>

<h2><i>Vertex</i></h2>
<table cellpadding='2' border='0' cellspacing='0' width='600px'>
<tbody>
<blockquote><tr>
<blockquote><td width='100'><b>Processing</b> </td>
<td width='100'><b>cprocessing</b></td>
<td width='400'><b>Description</b></td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/bezierVertex_.html'>bezierVertex()</a></td>
<td> <code>bezierVertex()</code></td>
<td> adds a Bézier arc to the shape</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/curveVertex_.html'>curveVertex()</a></td>
<td> <code>N/A</code></td>
<td> adds a Catmull-Rom arc to the shape</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/endShape_.html'>endShape()</a></td>
<td> <code>endShape()</code></td>
<td> finishes the shape</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/texture_.html'>texture()</a></td>
<td> <code>N/A</code></td>
<td></td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/textureMode_.html'>textureMode()</a></td>
<td> <code>N/A</code></td>
<td></td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/vertex_.html'>vertex()</a></td>
<td><code>vertex()</code></td>
<td> adds a vertex to the shape</td>
</blockquote></tr>
</blockquote><blockquote></tbody>
</table></blockquote>

<br>

<h1>Input</h1>

<h2><i>Mouse</i></h2>

<table cellpadding='2' border='0' cellspacing='0' width='600px'>
<tbody>
<blockquote><tr>
<blockquote><td width='100'><b>Processing</b> </td>
<td width='100'><b>cprocessing</b></td>
<td width='400'><b>Description</b></td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/mouseButton.html'>mouseButton</a></td>
<td> <code>mouseButton</code></td>
<td> tells what mouse button is pressed.</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/mouseClicked_.html'>mouseClicked()</a></td>
<td> <code>mouseClicked()</code></td>
<td> called when a mouse button is pressed and released</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/mouseDragged_.html'>mouseDragged()</a></td>
<td> <code>mouseDragged()</code></td>
<td>called when a mouse is dragged with a pressed button</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/mouseMoved_.html'>mouseMoved()</a></td>
<td> <code>mouseMoved()</code></td>
<td>called when a mouse is moved with buttons pressed</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/mousePressed_.html'>mousePressed()</a></td>
<td> <code>mousePressed()</code></td>
<td> called when a mouse button is pressed</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/mousePressed.html'>mousePressed</a></td>
<td> <code>mousePressed</code></td>
<td> tells whether a mouse button is pressed</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/mouseReleased_.html'>mouseReleased()</a></td>
<td> <code>mouseReleased()</code></td>
<td> called when a mouse button is released</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/mouseX.html'>mouseX</a></td>
<td> <code>mouseX</code></td>
<td> current <i>x</i> position of the mouse</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/mouseY.html'>mouseY</a></td>
<td> <code>mouseY</code></td>
<td> current <i>y</i> position of the mouse</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/pmouseX.html'>pmouseX</a></td>
<td><code>pmouseX</code></td>
<td> previous <i>x</i> position of the mouse</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/pmouseY.html'>pmouseY</a></td>
<td><code>pmouseY</code></td>
<td> previous <i>y</i> position of the mouse<br>
</td>
</blockquote></tr>
</blockquote><blockquote></tbody>
</table></blockquote>

<h2><i>Keyboard</i></h2>

<table cellpadding='2' border='0' cellspacing='0' width='600px'>
<tbody>
<blockquote><tr>
<blockquote><td width='100'><b>Processing</b> </td>
<td width='100'><b>cprocessing</b></td>
<td width='400'><b>Description</b></td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/key.html'>key</a></td>
<td> <code>key</code></td>
<td> holds the char value of the most recently pressed key</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/keyCode.html'>keyCode</a></td>
<td> <code>keyCode</code></td>
<td> holds an int code of the most recently pressed key</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/keyPressed_.html'>keyPressed()</a></td>
<td> <code>keyPressed()</code></td>
<td> called when a key is pressed</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/keyPressed.html'>keyPressed</a></td>
<td> <code>keyPressed</code></td>
<td> tells whether a key is pressed</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/keyReleased_.html'>keyReleased()</a></td>
<td> <code>keyReleased()</code></td>
<td> called when a key is released</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/keyTyped_.html'>keyTyped()</a></td>
<td> <code>keyTyped()</code></td>
<td> called when a non-code key is pressed</td>
</blockquote></tr>
</blockquote><blockquote></tbody>
</table>
<br></blockquote>

<h1>Math</h1>
<table cellpadding='2' border='0' cellspacing='0' width='600px'>
<tbody>
<blockquote><tr>
<blockquote><td width='100'><b>Processing</b> </td>
<td width='100'><b>cprocessing</b></td>
<td width='400'><b>Description</b></td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/PVector.html'>PVector</a></td>
<td> <code>PVector</code></td>
<td> a class used to describe two or three dimensional vectors</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/noise_.html'>noise()</a></td>
<td> <code>N/A</code></td>
<td> returns the perlin noise value at specified coordinates</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/binary_.html'>binary()</a></td>
<td> <code>N/A</code></td>
<td> converts a value to a string in binary notation</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/hex_.html'>hex()</a></td>
<td> <code>N/A</code></td>
<td> converts a value to a string in hexadecimal notation</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/unbinary_.html'>unbinary()</a></td>
<td> <code>N/A</code></td>
<td> converts a string in binary notation to its decimal value</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/unhex_.html'>unhex()</a></td>
<td> <code>N/A</code></td>
<td> converts a string in hexadecimal notation to its decimal value</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/byte_.html'>byte()</a></td>
<td> <code>N/A</code></td>
<td> converts a char or int to its byte representation</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/constrain_.html'>constrain()</a></td>
<td> <code>constrain()</code></td>
<td> returns the constrained value according to the received parameters</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/dist_.html'>dist()</a></td>
<td> <code>dist()</code></td>
<td> returns the Euclidean distance between two points</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/map_.html'>map()</a></td>
<td> <code>map()</code></td>
<td> re-maps a number from one range to another</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/mag_.html'>mag()</a></td>
<td> <code>mag()</code></td>
<td> returns the magnitude of a vector</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/lerp_.html'>lerp()</a></td>
<td> <code>lerp()</code></td>
<td> returns a interpolation between two numbers</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/sq_.html'>sq()</a></td>
<td> <code>sq()</code></td>
<td> returns the square of a value</td>
</blockquote></tr>
</blockquote><blockquote></tbody>
</table>
<br></blockquote>

<h1>Transform</h1>
<table cellpadding='2' border='0' cellspacing='0' width='600px'>
<tbody>
<blockquote><tr>
<blockquote><td width='100'><b>Processing</b> </td>
<td width='100'><b>cprocessing</b></td>
<td width='400'><b>Description</b></td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/applyMatrix_.html'>applyMatrix()</a></td>
<td> <code>applyMatrix()</code></td>
<td> multiplies the current transformation matrix by a<br>
given matrix</td>
</blockquote></tr></blockquote>

<blockquote><tr>
<blockquote><td><a href='http://www.processing.org/reference/getMatrix_.html'>getMatrix()</a></td>
<td> <code>getMatrix()</code></td>
<td> returns the MODELVIEW matrix</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/popMatrix_.html'>popMatrix()</a></td>
<td> <code>popMatrix()</code></td>
<td> discards the current (top) matrix from the<br>
transformation matrix stack</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/printMatrix_.html'>printMatrix()</a></td>
<td> <code>N/A</code></td>
<td> prints the current transformation matrix</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/pushMatrix_.html'>pushMatrix()</a></td>
<td> <code>pushMatrix()</code></td>
<td> pushes a copy of the current matrix onto the<br>
transformation matrix stack</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/resetMatrix_.html'>resetMatrix()</a></td>
<td> <code>resetMatrix()</code></td>
<td> sets an identity matrix as the the current<br>
transformation matrix</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/rotate_.html'>rotate()</a></td>
<td> <code>rotate()</code></td>
<td> rotates around a given axis</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/rotateX_.html'>rotateX()</a></td>
<td> <code>rotateX()</code></td>
<td> rotates around the <i>x</i> axis</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/rotateY_.html'>rotateY()</a></td>
<td> <code>rotateY()</code></td>
<td> rotates around the <i>y</i> axis</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/rotateZ_.html'>rotateZ()</a></td>
<td> <code>rotateZ()</code></td>
<td> rotates around the <i>z</i> axis</td>
</blockquote></tr></blockquote>

<blockquote><tr>
<blockquote><td><a href='http://processing.org/reference/shearX_.html'>shearX()</a></td>
<td> <code>N/A</code></td>
<td> shears a shape around the <i>x</i> axis</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://processing.org/reference/shearY_.html'>shearY()</a></td>
<td> <code>N/A</code></td>
<td> shears a shape around the <i>y</i> axis</td>
</blockquote></tr></blockquote>

<blockquote><tr>
<blockquote><td><a href='http://www.processing.org/reference/scale_.html'>scale()</a></td>
<td> <code>scale()</code></td>
<td> performs a scale transformation</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/translate_.html'>translate()</a></td>
<td> <code>translate()</code></td>
<td> performs a translation transformation</td>
</blockquote></tr>
</blockquote><blockquote></tbody>
</table>
<br></blockquote>

<h1>Lights, Camera</h1>
<h2><i>Lights</i></h2>
<table cellpadding='2' border='0' cellspacing='0' width='600px'>
<tbody>
<blockquote><tr>
<blockquote><td width='100'><b>Processing</b> </td>
<td width='100'><b>cprocessing</b></td>
<td width='400'><b>Description</b></td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/ambientLight_.html'>ambientLight()</a></td>
<td><code>ambientLight()</code></td>
<td>adds an ambient light source</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/directionalLight_.html'>directionalLight()</a></td>
<td><code>directionalLight</code></td>
<td> adds a directional light source</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/lightFalloff_.html'>lightFalloff()</a></td>
<td><code>lightFalloff()</code></td>
<td>sets attenuation factors for next light sources</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/lightSpecular_.html'>lightSpecular()</a></td>
<td><code>lightSpecular()</code></td>
<td>sets specular coefficients for next light sources</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/lights_.html'>lights()</a></td>
<td><code>lights()</code></td>
<td> turns on lighting and default light sources</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/noLights_.html'>noLights()</a></td>
<td><code>noLights()</code></td>
<td> turns off lighting</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/normal_.html'>normal()</a></td>
<td><code>N/A</code></td>
<td> sets the normal vector for subsequent vertices</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/pointLight_.html'>pointLight()</a></td>
<td><code>pointLight()</code></td>
<td>adds a point light source</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/spotLight_.html'>spotLight()</a></td>
<td><code>spotLight()</code></td>
<td> adds a spot light source</td>
</blockquote></tr>
</blockquote><blockquote></tbody>
</table></blockquote>

<h2><i>Camera</i></h2>
<table cellpadding='2' border='0' cellspacing='0' width='600px'>
<tbody>
<blockquote><tr>
<blockquote><td width='100'><b>Processing</b> </td>
<td width='100'><b>cprocessing</b></td>
<td width='400'><b>Description</b></td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/beginCamera_.html'>beginCamera()</a></td>
<td><code>N/A</code></td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/camera_.html'>camera()</a></td>
<td><code>camera()</code></td>
<td>sets the camera transformation</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/endCamera_.html'>endCamera()</a></td>
<td><code>N/A</code></td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/frustum_.html'>frustum()</a></td>
<td><code>N/A</code></td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/ortho_.html'>ortho()</a></td>
<td><code>ortho()</code></td>
<td> sets an orthogonal projection</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/perspective_.html'>perspective()</a></td>
<td><code>perspective()</code></td>
<td> sets a perspective projection</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/printCamera_.html'>printCamera()</a></td>
<td><code>N/A</code></td>
<td> prints the current transformation matrix</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/getProjection_.html'>getProjection()</a></td>
<td> <code>N/A</code></td>
<td> returns the PROJECTION matrix</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/printProjection_.html'>printProjection()</a></td>
<td><code>N/A</code></td>
<td> prints the current projection matrix</td>
</blockquote></tr>
</blockquote><blockquote></tbody>
</table></blockquote>

<h2><i>Coordinates</i></h2>
<table cellpadding='2' border='0' cellspacing='0' width='600px'>
<tbody>
<blockquote><tr>
<blockquote><td width='100'><b>Processing</b> </td>
<td width='100'><b>cprocessing</b></td>
<td width='400'><b>Description</b></td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/modelX_.html'>modelX()</a></td>
<td><code>N/A</code></td>
<td> returns the screen <i>x</i> coordinate of given object<br>
coordinates</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/modelY_.html'>modelY()</a></td>
<td><code>modelY()</code></td>
<td>returns the screen <i>y</i> coordinate of given object<br>
coordinates</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/modelZ_.html'>modelZ()</a></td>
<td><code>N/A)</code></td>
<td>returns the screen <i>z</i> coordinate of given object<br>
coordinates</td>
</blockquote></tr>
<tr>
<blockquote><td><span></span>N/A</td>
<td><code>N/A</code></td>
<td> returns the screen coordinates of given object<br>
coordinates</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/screenX_.html'>screenX()</a></td>
<td><code>screenX()</code></td>
<td>returns the screen <i>x</i> coordinate of given object<br>
coordinates</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/screenY_.html'>screenY()</a></td>
<td><code>screenY()</code></td>
<td>returns the screen <i>y</i> coordinate of given object<br>
coordinates</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/screenZ_.html'>screenZ()</a></td>
<td><code>screenY()</code></td>
<td>returns the screen <i>z</i> coordinate of given object<br>
coordinates</td>
</blockquote></tr>
<tr>
<blockquote><td><span></span>N/A</td>
<td><code>screenXYZ()</code></td>
<td> returns the screen coordinates of given object<br>
coordinates</td>
</blockquote></tr>
</blockquote><blockquote></tbody>
</table></blockquote>

<h2><i>Material Properties</i></h2>
<table cellpadding='2' border='0' cellspacing='0' width='600px'>
<tbody>
<blockquote><tr>
<blockquote><td width='100'><b>Processing</b> </td>
<td width='100'><b>cprocessing</b></td>
<td width='400'><b>Description</b></td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/ambient_.html'>ambient()</a></td>
<td><code>ambient()</code></td>
<td> sets the ambient properties of the next vertices</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/emissive_.html'>emissive()</a></td>
<td><code>emissive()</code></td>
<td> sets the emissive properties of the next vertices</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/shininess_.html'>shininess()</a></td>
<td><code>shininess()</code></td>
<td> sets the shininess property of the next vertices</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/specular_.html'>specular()</a></td>
<td><code>cspecular()</code></td>
<td> sets the specular properties of the next vertices</td>
</blockquote></tr>
</blockquote><blockquote></tbody>
</table></blockquote>

<h1>Image</h1>

<table cellpadding='2' border='0' cellspacing='0' width='600px'>
<tbody>
<blockquote><tr>
<blockquote><td width='100'><b>Processing</b> </td>
<td width='100'><b>cprocessing</b></td>
<td width='400'><b>Description</b></td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/createImage_.html'>createImage()</a></td>
<td> <code>N/A</code></td>
<td> creates an empty PImage object</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/filter_.html'>filter()</a></td>
<td> <code>N/A</code></td>
<td> applies a filter to the display window</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/image_.html'>image()</a></td>
<td> <code>N/A</code></td>
<td> displays a PImage object</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/imageMode_.html'>imageMode()</a></td>
<td> <code>N/A</code></td>
<td> changes the semantics of the arguments of <code>image()</code> </td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/loadImage_.html'>loadImage()</a></td>
<td> <code>N/A</code></td>
<td> loads an image into a PImage object</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/loadPixels_.html'>loadPixels()</a></td>
<td> <code>N/A</code></td>
<td> loads the current canvas data into screen.pixels</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/updatePixels_.html'>updatePixels()</a></td>
<td> <code>N/A</code></td>
<td> displays the data from screen.pixels</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/get_.html'>get()</a></td>
<td> <code>N/A</code></td>
<td> returns a copy, a part of a pixel of the screen</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/set_.html'>set()</a></td>
<td> <code>N/A</code></td>
<td> sets a position of the screen with data</td>
</blockquote></tr>
</blockquote><blockquote></tbody>
</table>
<br></blockquote>

<h1>Text</h1>
<table cellpadding='2' border='0' cellspacing='0' width='600px'>
<tbody>
<blockquote><tr>
<blockquote><td width='100'><b>Processing</b> </td>
<td width='100'><b>cprocessing</b></td>
<td width='400'><b>Description</b></td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/textAlign_.html'>textAlign()</a></td>
<td> <code>N/A</code></td>
<td> changes the text alignment attributes</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/createFont_.html'>createFont()</a></td>
<td> <code>N/A</code></td>
<td> creates a font</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/textFont_.html'>textFont()</a></td>
<td> <code>N/A</code></td>
<td> sets the received font as current font</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/htmlText_.html'>htmlText()</a></td>
<td> <code>N/A</code></td>
<td> draws the html text at the given position</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/text_.html'>text()</a></td>
<td> <code>N/A</code></td>
<td> draws the text at the given position</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/textSize_.html'>textSize()</a></td>
<td> <code>N/A</code></td>
<td> changes the current font size</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/textWidth_.html'>textWidth()</a></td>
<td> <code>N/A</code></td>
<td> returns the width of the received string rendered in the current font</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/textAscent_.html'>textAscent()</a></td>
<td> <code>N/A</code></td>
<td> returns the ascent of the current font</td>
</blockquote></tr>
<tr>
<blockquote><td><a href='http://www.processing.org/reference/textDescent_.html'>textDescent()</a></td>
<td> <code>N/A</code></td>
<td> returns the descent of the current font</td>
</blockquote></tr>
</blockquote><blockquote></tbody>
</table>
<br>