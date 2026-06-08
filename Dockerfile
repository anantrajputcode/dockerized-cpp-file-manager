FROM gcc:latest

WORKDIR /app

COPY . .

RUN g++ main.cpp -o main

CMD ["./main"]