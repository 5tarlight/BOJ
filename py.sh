mkdir ./boj/$1
cp ./boj-py/ps.py ./boj/$1/$2.py
git add .
git commit -m "$2"
