class PlayerPaddle
{
   constructor(context)
   {
      //we define instance variables in the constructor.
      //NOTE: in C++ this isn't the case.
      this.height = 150;
      this.width = 25;
      this.x = 3;
      this.y = context.canvas.height / 2;
      this.color = "rgb(0,0,0)";

      //rate at which the paddle moves on the screen
      this.speed = 3;

      //where the paddle will be drawn
      this.context = context;

      //tracks mouse's y coordinate
      this.mouse_y = context.canvas.height / 2;
      this.dead_zone = 7;

      //always ensure that "this" means our local instance instead of
      //something else 
      this.mouseMove = this.mouseMove.bind(this);

      //listen for mouse movements
      this.context.canvas.addEventListener("mousemove", this.mouseMove);
   }

   //called whenever the mouse moves
   mouseMove(evt)
   {
      var rect = this.context.canvas.getBoundingClientRect();
      this.mouse_y = evt.clientY - rect.top;
   }

   //responsible for altering the movement of the player's paddle
   update()
   {
      if(this.mouse_y > this.y + this.dead_zone)
      {
         if(this.y + this.height / 2 < this.context.canvas.height)
         {
            this.y += this.speed;
         }  
      }
      else if(this.mouse_y < this.y - this.dead_zone)
      {
         if(this.y - this.height / 2 > 0)
         {
            this.y -= this.speed;
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
   }
}
