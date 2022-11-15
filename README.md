# ALG1-TP2
Repository to save my ALG1-TP2 Implementation.
This implementation works using really little time and is 100% accurate to stock and extra test-cases.
It's the forth functional implementation. The first one was using dynamic programming, the second one was too slow, and, after that, I've used struct, and this one is using POO.

## Compiling and Running the Program
First of all, clone this repo into a folder of your preference inside your machine by opening a terminal inside that folder and than enter the project folder by running these commands:
```
git clone https://github.com/matheusflavio/ALG1-TP2.git
cd ALG1-TP2
```
Then, build the tp02 executable. To do that, use the terminal that previously is located inside the project root folder and run the command:
```
makethird
```
After that, run a test instance by using a command like this:
```
./tp02 < input/input.txt
```

You can test the output of single inputs like that by running:
```
diff <(./tp02 < input/input.txt) output/input-out.txt
```

Or, if you want to try the additional tests command, run on the terminal a command like this:
```
bash run_tests.sh
```
Note that 'input/input.txt' is just a location of a .txt file named 'input.txt' that comes within this repository. It can be used with any location and any .txt file. By running the command that way, the terminal show a line with two integers, one for the first presente show and the other one to the last present show, and so on until the "0 0" input shows on the .txt input file.
In addition, the additional test cases include a 102M file, and, because of that, it cannot be uploaded to github. I'll add a link to a Google Drive to make its download available.
[Link para download dos testes adicionais](https://drive.google.com/file/d/1mcS8qprrqAcg5z8LI2Q3MTSwR5htGRjF/view?usp=sharing)

## Cleaning compiled files
Just run on the terminal:
```
make clean
```
