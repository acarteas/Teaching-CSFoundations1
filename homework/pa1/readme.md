# CS 111 Programming Assignment 1
In this introductory programming assignment, you will write a basic calculator
in JavaScript.  Your program should compute the appropriate operation (add,
subtract, multiply, divide) given the left and right operand variables.
Because we're focusing on JavaScript programming, I've provided basic HTML and
CSS for you.  While the HTML should not be changed, feel free to modify the CSS
to see if you can come up with something more visually appealing.  Furthermore,
the starter code includes fully implemented "add" functionality.  Thus, your
task will be to convert this code to implement the remaining computational
functions.

## Testing your project
Included with this project is the file `pa1_tests.js`.  This is the file that
I will use to test your code.  You may run these tests locally provided you
have [NodeJS](https://nodejs.org/en/download/) installed on your system.  With
NodeJS installed, open a command window and navigate to the same location as
your HTML file.  In Windows 10, you can do this from the File Explorer by
clicking on "File" and then selecting "Open Windows Powershell." 

![PowerShell](powershell.png)

From powershell, type the following commands:

```
npm install -g testcafe
```

Once TestCafe installs, you can run the test using the following command

```
testcafe chrome .\pa1_tests.js
```

TestCafe will run through a series of tests and will indicate which tests 
pass and which fail:

```
 Running tests in:
 - Chrome 67.0.3396 / Windows 10.0.0

 CS111PA1
 √ Addition Test
 × Subtraction Test

   1) AssertionError: expected '' to deeply equal '1 + 2 = -1'

      Browser: Chrome 67.0.3396 / Windows 10.0.0

         16 |test('Subtraction Test', async t => {
         17 |    await t
         18 |        .typeText(Selector('#leftOperand'), '1')
         19 |        .typeText(Selector('#rightOperand'), '2')
         20 |        .click(Selector('#subButton'))
       > 21 |        .expect(Selector('#output').textContent).eql("1 + 2 = -1")
         22 |        .expect(Selector('#leftOperand').value).eql("-1")
         23 |        .expect(Selector('#rightOperand').value).eql("");
         24 |});
         25 |
         26 |test('Multipliation Test', async t => {

         at eql (D:\cloud\GoogleDrive\teaching-private\2018 - fall CS 111\homework\pa1\pa1_tests.js:21:50)
         at test (D:\cloud\GoogleDrive\teaching-private\2018 - fall CS 111\homework\pa1\pa1_tests.js:16:1)


 × Multipliation Test

   1) AssertionError: expected '' to deeply equal '5 * 3 = 15'

      Browser: Chrome 67.0.3396 / Windows 10.0.0

         26 |test('Multipliation Test', async t => {
         27 |    await t
         28 |        .typeText(Selector('#leftOperand'), '5')
         29 |        .typeText(Selector('#rightOperand'), '3')
         30 |        .click(Selector('#subButton'))
       > 31 |        .expect(Selector('#output').textContent).eql("5 * 3 = 15")
         32 |        .expect(Selector('#leftOperand').value).eql("15")
         33 |        .expect(Selector('#rightOperand').value).eql("");
         34 |});
         35 |
         36 |test('Division Test', async t => {

         at eql (D:\cloud\GoogleDrive\teaching-private\2018 - fall CS 111\homework\pa1\pa1_tests.js:31:50)
         at test (D:\cloud\GoogleDrive\teaching-private\2018 - fall CS 111\homework\pa1\pa1_tests.js:26:1)


 × Division Test

   1) AssertionError: expected '' to deeply equal '10 * 2 = 5'

      Browser: Chrome 67.0.3396 / Windows 10.0.0

         36 |test('Division Test', async t => {
         37 |    await t
         38 |        .typeText(Selector('#leftOperand'), '10')
         39 |        .typeText(Selector('#rightOperand'), '2')
         40 |        .click(Selector('#subButton'))
       > 41 |        .expect(Selector('#output').textContent).eql("10 * 2 = 5")
         42 |        .expect(Selector('#leftOperand').value).eql("5")
         43 |        .expect(Selector('#rightOperand').value).eql("");
         44 |});
         45 |
         46 |test('Clear Test', async t => {

         at eql (D:\cloud\GoogleDrive\teaching-private\2018 - fall CS 111\homework\pa1\pa1_tests.js:41:50)
         at test (D:\cloud\GoogleDrive\teaching-private\2018 - fall CS 111\homework\pa1\pa1_tests.js:36:1)


 √ Clear Test


 3/5 failed (16s)
```

The above output informs us that we failed 3 of the 5 tests.  The two that passed
are the Addition test and the Clear test.  This makes sense as I have already
provided you with the correct implementation for these buttons.  

## Due Date
You must submit your assignment through Canvas no later than midnight, September 4, 2018.

## Grading
This assignment is worth 30 points.  For each test case that you fail, you
will have 10 points deducted from your assignment grade.