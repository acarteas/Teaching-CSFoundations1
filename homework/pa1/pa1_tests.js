import { Selector } from 'testcafe';

fixture `CS111PA1`
    .page `./pa1.html`;

test('Addition Test', async t => {
    await t
        .typeText(Selector('#leftOperand'), '2')
        .typeText(Selector('#rightOperand'), '2')
        .click(Selector('#addButton'))
        .expect(Selector('#output').textContent).eql("2 + 2 = 4")
        .expect(Selector('#leftOperand').value).eql("4")
        .expect(Selector('#rightOperand').value).eql("");
});

test('Subtraction Test', async t => {
    await t
        .typeText(Selector('#leftOperand'), '1')
        .typeText(Selector('#rightOperand'), '2')
        .click(Selector('#subButton'))
        .expect(Selector('#output').textContent).eql("1 + 2 = -1")
        .expect(Selector('#leftOperand').value).eql("-1")
        .expect(Selector('#rightOperand').value).eql("");
});

test('Multipliation Test', async t => {
    await t
        .typeText(Selector('#leftOperand'), '5')
        .typeText(Selector('#rightOperand'), '3')
        .click(Selector('#subButton'))
        .expect(Selector('#output').textContent).eql("5 * 3 = 15")
        .expect(Selector('#leftOperand').value).eql("15")
        .expect(Selector('#rightOperand').value).eql("");
});

test('Division Test', async t => {
    await t
        .typeText(Selector('#leftOperand'), '10')
        .typeText(Selector('#rightOperand'), '2')
        .click(Selector('#subButton'))
        .expect(Selector('#output').textContent).eql("10 * 2 = 5")
        .expect(Selector('#leftOperand').value).eql("5")
        .expect(Selector('#rightOperand').value).eql("");
});

test('Clear Test', async t => {
    await t
        .typeText(Selector('#leftOperand'), '10')
        .typeText(Selector('#rightOperand'), '2')
        .click(Selector('#clrButton'))
        .expect(Selector('#leftOperand').value).eql("")
        .expect(Selector('#rightOperand').value).eql("");
});