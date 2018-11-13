class Ball
{
   constructor(context)
   {
      this.context = context;
      this.x = this.context.canvas.width / 2;
      this.y = this.context.canvas.height / 2;
      this.dx = 2;
      this.dy = 2;
      this.color = "rgb(255,0,0)";
      this.width = 25;
   }

   bounceUp()
   {
      this.dy = -Math.ceil(Math.random() * 6 + 1);
   }

   bounceDown()
   {
      this.dy = Math.ceil(Math.random() * 6 + 1);
   }

   bounceLeft()
   {
      this.dx = -Math.ceil(Math.random() * 6 + 1);
   }

   bounceRight()
   {
      this.dx = Math.ceil(Math.random() * 6 + 1);
   }

   checkBoundaryCollision()
   {
      var boundary = this.width / 2;

      //too far down?
      if(this.context.canvas.height - boundary < this.y && this.dy > 1)
      {
         this.bounceUp();
      }

      //too far up?
      if(0 + boundary > this.y && this.dy < 1)
      {
         this.bounceDown();
      }

      //to far right?
      if(this.context.canvas.width - boundary < this.x && this.dx > 1)
      {
         this.bounceLeft();
      }

      //too far left?
      else if(0 + boundary > this.x && this.dx < 1)
      {
         this.bounceRight();
      }
   }

   update()
   {
      //move the ball
      for(var i = 0; i < Math.abs(this.dx); i++)
      {
         this.x += Math.sign(this.dx) * 1;
         this.checkBoundaryCollision();
      }
      for(var i = 0; i < Math.abs(this.dy); i++)
      {
         this.y += Math.sign(this.dy) * 1;
         this.checkBoundaryCollision();
      }
   }

   render()
   {
      this.context.beginPath();
      this.context.fillStyle = this.color;
      this.context.arc(this.x,
                       this.y,
                       this.width/2,
                       0,
                       Math.PI * 2,
                       true);
      this.context.fill();
   }
}