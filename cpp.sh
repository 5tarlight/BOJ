levels=("except" "bronze" "silver" "gold" "platinum" "diamond" "ruby")

# Check level input correctly
if [[ ! " ${levels[@]} " =~ " $1 " ]]; then
    echo "Error: Invalid difficulty level. Choose from: ${levels[*]}"
    exit 1
fi

# Create folder if not exists
if [[ ! -d "./boj/$1" ]]; then
    mkdir ./boj/$1
fi

cp ./boj-cpp/main.cpp ./boj/$1/$2.cpp
git add .
git commit -m "$2"

