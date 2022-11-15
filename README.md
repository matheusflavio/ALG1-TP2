# ALG1-TP2
Repository to save my ALG1-TP2 Implementation.
This implementation for now timeouts on the the big_input of the additional test cases.

## Compiling and Running the Program
First of all, clone this repo into a folder of your preference inside your machine by openinng a terminal inside that folder and than enter the project folder by running these commands:
```
git clone https://github.com/matheusflavio/ALG1-TP2.git
cd ALG1-TP2
```
Then, build the tp02 executable. To do that, use the terminal that previously is located inside the project root folder and run the command:
```
make
```
After that, run a test instance by using a command like this:
```
./tp02 < input/input.txt
```
Or, if you want to the additional command like this:
```
bash run_tests.sh
```
Note that 'input/input.txt' is just a location of a .txt file named 'input.txt' that comes within this repository. It can be used with any location and any .txt file. By running the command that way, the terminal show a line for each case written "yes" if that case is satisfying or "nao" if it's not. That way, line 1 is the answer for test 1, line 2 for the test 2, and so on until the "0 0" input shows on the .txt file.
In addition, the additional test_cases include a 102M file, and that cannot be uploaded to github. I'll add a link to a Google Drive to make its download avaliable.

## Cleaning .o files and the Executable
Just run on the terminal:
```
make clean
```
