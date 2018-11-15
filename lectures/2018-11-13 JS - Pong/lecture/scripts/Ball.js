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

      //the Ball class uses this to track what it might collide with
      this.other_pieces = [];
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

   checkOtherPieceCollision()
   {
      var boundary = this.width / 2;
      var left = this.x - boundary;
      var right = this.x + boundary;
      var radius = this.width / 2;
      var upper_y = this.y - radius;
      var lower_y = this.y + radius;
      for(let piece of this.other_pieces)
      {
         //is the ball within the vertical boundary of the particular piece
         var piece_top = piece.y - piece.height / 2;
         var piece_bottom = piece.y + piece.height / 2;
         if(upper_y >= piece_top && lower_y <= piece_bottom)
         {
            var piece_left = piece.x - piece.width / 2;
            var piece_right = piece.x + piece.width / 2;
            if(left < piece_right && right > piece_left)
            {
               if(this.dx > 0)
               {
                  this.bounceLeft();
               }
               else
               {
                  this.bounceRight();
               }
            }
         }
      }
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
         this.checkOtherPieceCollision();
      }
      for(var i = 0; i < Math.abs(this.dy); i++)
      {
         this.y += Math.sign(this.dy) * 1;
         this.checkBoundaryCollision();
         this.checkOtherPieceCollision();
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

      var center = this.y;
      this.context.beginPath();
      this.context.moveTo(this.context.canvas.width,center);
      this.context.lineTo(0,center);
      this.context.stroke();

      this.context.beginPath();
      this.context.moveTo(this.x, this.context.canvas.height);
      this.context.lineTo(this.x,0);
      this.context.stroke();
   }
}