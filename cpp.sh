mkdir ./boj/$1
cp ./boj-cpp/main.cpp ./boj/$1/$2.cpp
git add .
git commit -m "$2"
