####### Run the tests with this script #######

# Test files are trivial_input.txt, small_input.txt, medium_input.txt and big_input.txt inside the test_files folder
# The binary file is called "tp02"

# The corret output files are trivial_output.txt, small_output.txt, medium_output.txt and big_output.txt
# The timeout is 30 seconds (about 3 seconds per case)

# clean the output files
if test -d "test_files"; then
    echo "Download not needed"
else
    wget "https://drive.google.com/u/1/uc?id=1mcS8qprrqAcg5z8LI2Q3MTSwR5htGRjF&export=download" -O tests.7z
    7z x tests.7z -y
fi

if test -f "compactGameFiles.sh"; then
    rm compactGameFiles.sh
fi

if test -f "tests.7z"; then
    rm tests.7z
fi

echo "Starting tests..."

for i in trivial_input.txt small_input.txt medium_input.txt big_input.txt
do
    echo -n "Running test $i ... "

    diff -q <(./tp02 < test_files/$i) test_files/${i/input/output}
    if [ $? -eq 0 ]
    then
        echo "---> Passed!"
    else
        echo "---> Failed :/"
    fi
done