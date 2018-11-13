class PlayerPaddle
{

   constructor(context)
   {
      this.x = 3;
      this.y = 3;
      this.dx = 1;
      this.dy = 1;
      this.mouse_x = 0;
      this.width = 25;
      this.height = 150;
      this.speed = 3;
      this.dead_zone = 5;
      this.fillStyle = "rgb(0,0,0)";
      this.context = context;
      this.max_width = context.canvas.width;
      this.max_height = context.canvas.height;

      this.mouseMove = this.mouseMove.bind(this);

      context.canvas.addEventListener("mousemove", this.mouseMove);
   }

   mouseMove(evt)
   {
      var rect = this.context.canvas.getBoundingClientRect();
      this.mouse_y = evt.clientY - rect.top;
   }

   isInsideBoundary(x, y)
   {
      if(x > this.x && x < this.x + this.width)
      {
         var half_height = this.height / 2;
         if(y > this.y  - half_height && y < this.y + half_height)
         {
            return true;
         }
      }
      return false;
   }

   update()
   {
      if(this.mouse_y > this.y + this.dead_zone)
      {
         this.y += this.speed;
      }
      else if(this.mouse_y < this.y - this.dead_zone)
      {
         this.y -= this.speed;
      }
   }

   render()
   {
      context.fillStyle = this.fillStyle;
      var half_height = this.height / 2;
      this.context.fillRect(this.x, this.y - half_height, this.width, this.height);
   }
}
