class Pong
{
   constructor(context)
   {
      this.ball = new Ball(context);
      this.player_paddle = new PlayerPaddle(context);
      this.computer_paddle = new ComputerPaddle(context);
      this.max_width = context.canvas.width;
      this.max_height = context.canvas.height;
      this.context = context;

      this.pieces = [];
      this.pieces.push(this.ball);
      this.pieces.push(this.player_paddle);
      this.pieces.push(this.computer_paddle);

      this.ball.addCollidablePiece(this.player_paddle);
      this.ball.addCollidablePiece(this.computer_paddle);

      this.renderLoop = this.renderLoop.bind(this);
   }

   playGame()
   {
      this.renderLoop();
   }

   renderLoop()
   {
      //ask for a new page in our flip book
      this.context.clearRect(0, 0, this.max_width, this.max_height);
      
      //draw all pieces
      for(let piece of this.pieces)
      {
         piece.update();
         piece.render();
      }

      window.requestAnimationFrame(this.renderLoop);
   }
}