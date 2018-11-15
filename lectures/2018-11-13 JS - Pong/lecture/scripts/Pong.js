class Pong
{
   //this is a class function.  Sometimes these are called
   //class methods.
   //constructor is a special function that gets called whenever
   //we create a new instance of this Pong class.
   constructor(context)
   {
      //this.XXX means that we are creating a variable
      //that belongs to a particular instance of a class
      //These variables are called "instance variables"
      this.max_width = context.canvas.width;
      this.max_height = context.canvas.height;
      this.context = context;

      this.player_paddle = new PlayerPaddle(context);
      this.ball = new Ball(context);
      this.computer_paddle = new ComputerPaddle(context, this.ball);

      //tell ball about the paddles
      this.ball.other_pieces.push(this.player_paddle);
      this.ball.other_pieces.push(this.computer_paddle);

      //declare an array called movable_pieces
      this.movable_pieces = [];
      this.movable_pieces.push(this.player_paddle);
      this.movable_pieces.push(this.ball);
      this.movable_pieces.push(this.computer_paddle);

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

      //draw all movable pieces on the board
      for(let piece of this.movable_pieces)
      {
         piece.update();
         piece.render();
      }

      window.requestAnimationFrame(this.renderLoop);
   }
}