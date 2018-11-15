class ComputerPaddle
{
   constructor(context, ball)
   {
      //we define instance variables in the constructor.
      //NOTE: in C++ this isn't the case.
      this.height = 150;
      this.width = 25;
      this.x = context.canvas.width - this.width - 3;
      this.y = context.canvas.height / 2;
      this.color = "rgb(0,0,0)";

      //save reference to the ball for later use
      this.ball = ball;

      //helps smooth out the "jumpy" paddle issue when tracking balls that
      //dont move quick in the Y direction
      this.dead_zone = 20;

      //rate at which the paddle moves on the screen
      this.speed = 3;

      //where the paddle will be drawn
      this.context = context;

   }

   //responsible for altering the movement of the player's paddle
   update()
   {
      //if center of paddle is above the ball, move down
      //otherwise, if the center of the paddle is below the ball, move up
      var center = this.y;
      var dy = Math.abs(this.ball.dy);
      if(center < this.ball.y)
      {
         //if the ball is moving slower than our fastest movement speed, 
         //only move by the balls speed
         if(this.y + this.height / 2 < this.context.canvas.height)
         {
            if(dy < this.speed)
            {
               this.y += dy;
            }
            else
            {
               this.y += this.speed;
            }
      }
      }
      else if(center > this.ball.y)
      {
         if(this.y - this.height / 2 > 0)
         {
            if(dy < this.speed)
            {
               this.y -= dy;
            }
            else
            {
               this.y -= this.speed;
            }
         }
      }
   }

   //this function is responsible for drawing the paddle on the
   //supplied drawing context.
   render()
   {
      this.context.fillStyle = this.color;
      this.context.fillRect(this.x, 
                            this.y - this.height / 2, 
                            this.width, 
                            this.height
                            );

      //debug feature.  Comment out if not needed
      /*
      var center = this.y;
      this.context.beginPath();
      this.context.moveTo(this.x,center);
      this.context.lineTo(0,center);
      this.context.stroke();
      */
   }
}