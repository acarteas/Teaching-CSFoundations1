class ComputerPaddle
{

   constructor(context)
   {
      this.x = 0;
      this.y = 0;
      this.dx = 1;
      this.dy = 1;
      this.fillStyle = "rgb(0,0,0)";
      this.context = context;
      this.max_width = context.canvas.width;
      this.max_height = context.canvas.height;
      this.height = 150;
      this.width = 25;
   }

   isInsideBoundary(x, y)
   {
      return false;
      if(x > this.x && x < this.x + this.width)
      {
         if(y > this.y && y < this.y + this.height)
         {
            return true;
         }
      }
      return false;
   }

   update()
   {

   }

   render()
   {
      
   }
}
