class Ball
{
   constructor(context)
   {
      this.dx = 2;
      this.dy = 2;
      this.fillStyle = "rgb(255,0,0)";
      this.width = 25;
      this.context = context;
      this.max_width = context.canvas.width;
      this.max_height = context.canvas.height;
      this.x = this.max_height / 2;
      this.y = this.max_width / 2;
      this.other_pieces = [];
   }

   addCollidablePiece(piece)
   {
      this.other_pieces.push(piece);
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

      //too far down
      if(this.max_height - boundary < this.y && this.dy > 1)
      {
         this.bounceUp();
      }

      //too far up
      else if(0 + boundary > this.y && this.dy < 1)
      {
         this.bounceDown();
      }

      //too far right
      if(this.max_width - boundary < this.x && this.dx > 1)
      {
         this.bounceLeft();
      }

      //too far left
      else if(0 + boundary > this.x && this.dx < 1)
      {
         this.bounceRight();
      }
   }

   checkPieceCollision()
   {
      var boundary = this.width / 2;
      var top = this.y + boundary;
      var bottom = this.y - boundary;
      var left = this.x - boundary;
      var right = this.x + boundary;

      for(let piece of this.other_pieces)
      {
         if(piece.isInsideBoundary(this.x, top) === true && this.dy < 1)
         {
            this.bounceDown();
         }
         else if(piece.isInsideBoundary(this.x, bottom) && this.dy > 1)
         {
            this.bounceUp();
         }
         
         if(piece.isInsideBoundary(left, this.y) === true && this.dx < 1)
         {
            this.bounceRight();
         }
         else if(piece.isInsideBoundary(right, this.y) === true && this.dx > 1)
         {
            this.bounceLeft();
         }
      }
   }

   //all collision detection functionality goes here
   checkCollision()
   {
      this.checkBoundaryCollision();
      this.checkPieceCollision();
   }

   //updates ball on screen
   update()
   {
      //move circle
      for(var i = 0; i < Math.abs(this.dx); i++)
      {
         this.x += Math.sign(this.dx) * 1;
         this.checkCollision();
      }
      for(var i = 0; i < Math.abs(this.dy); i++)
      {
         this.y += Math.sign(this.dy) * 1;
         this.checkCollision();
      }
   }

   //renders ball on screen
   render()
   {
      context.beginPath();
      context.fillStyle = this.fillStyle;
      context.arc(
       this.x, 
       this.y, 
       this.width/2, 
          0, 
          Math.PI * 2, 
          true);
      context.fill();
   }
}