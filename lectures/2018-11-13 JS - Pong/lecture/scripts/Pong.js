class Pong
{
   constructor(context)
   {
      this.max_width = context.canvas.width;
      this.max_height = context.canvas.height;
      this.context = context;

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

      window.requestAnimationFrame(this.renderLoop);
   }
}