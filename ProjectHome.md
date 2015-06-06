# Objective #
Library which tries to recreate in C++ the intuitive graphics API of the Processing language / IDE.

# Usage #
Usage is very similar to the Processing framework, but you must explicitly import the cprocessing namespace
<table>
<tr>
<td>
<img src='http://www.processing.org/learning/drawing/imgs/1.11.jpg' />
</td>
<td>
<pre><code>//
// Processing 
//
void setup() {
    size(200,200);
}

void draw() {
   rectMode(CENTER);
   rect(100,100,20,100);
   ellipse(100,70,60,60);
   ellipse(81,70,16,32); 
   ellipse(119,70,16,32); 
   line(90,150,80,160);
   line(110,150,120,160);
}
</code></pre>
</td>
<td>
<pre><code>// 
// cprocessing 
//
#include &lt;cprocessing.hpp&gt;
using namespace cprocessing;

void setup(){
  size(200,200);
}
void draw(){
  rectMode(CENTER);
  rect(100,100,20,100);
  ellipse(100,70,60,60);
  ellipse(81,70,16,32); 
  ellipse(119,70,16,32); 
  line(90,150,80,160);
  line(110,150,120,160);
}
</code></pre>
</td>
</tr>
</table>