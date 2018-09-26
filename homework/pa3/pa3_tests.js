import { Selector } from 'testcafe';

fixture `CS111PA3`
    .page `./pa3.html`;

test('Forward Test', async t => {
    await t
        .typeText(Selector('#TurtleCommands'), 'F\n100')
        .click(Selector('#RunCommandsButton'))
        .expect(Selector('#Output').textContent).eql("forward(100)")
});

test('Right Test', async t => {
    await t
    .typeText(Selector('#TurtleCommands'), 'R\n90')
    .click(Selector('#RunCommandsButton'))
    .expect(Selector('#Output').textContent).eql("right(90)")
});

test('Left Test', async t => {
   await t
   .typeText(Selector('#TurtleCommands'), 'L\n90')
   .click(Selector('#RunCommandsButton'))
   .expect(Selector('#Output').textContent).eql("left(90)")
});


test('Back Test', async t => {
   await t
   .typeText(Selector('#TurtleCommands'), 'B\n120')
   .click(Selector('#RunCommandsButton'))
   .expect(Selector('#Output').textContent).eql("back(120)")
});

test('Squares Test', async t => {
   await t
   .typeText(Selector('#TurtleCommands'), 'F\n100\nL\n90\nF\n100\nL\n90\nF\n100\nL\n90\nF\n100\nL\n90\nB\n100\nR\n90\nB\n100\nR\n90\nB\n100')
   .click(Selector('#RunCommandsButton'))
   .expect(Selector('#Output').textContent).eql("forward(100)\nleft(90)\nforward(100)\nleft(90)\nforward(100)\nleft(90)\nforward(100)\nleft(90)\nback(100)\nright(90)\nback(100)\nright(90)\nback(100)")
});

test('Hex Test', async t => {
   await t
   .typeText(Selector('#TurtleCommands'), 'F\n110\nL\n60\nF\n110\nL\n60\nF\n110\nL\n60\nF\n110\nL\n60\nF\n110\nL\n60\nF\n110\nL\n60\nF\n110\nR\n60\nB\n110\nR\n60\nB\n110\nR\n60\nB\n110\nR\n60\nB\n110\nR\n60\nB\n110\nR\n60\nB\n110')
   .click(Selector('#RunCommandsButton'))
   .expect(Selector('#Output').textContent).eql("forward(110)\nleft(60)\nforward(110)\nleft(60)\nforward(110)\nleft(60)\nforward(110)\nleft(60)\nforward(110)\nleft(60)\nforward(110)\nleft(60)\nforward(110)\nright(60)\nback(110)\nright(60)\nback(110)\nright(60)\nback(110)\nright(60)\nback(110)\nright(60)\nback(110)\nright(60)\nback(110)")
});


