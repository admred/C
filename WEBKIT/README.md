apt-get install gcc libc6-dev libgtk-3-dev libwebkit2gtk-4.0-dev

git clone https://github.com/admred/C

gcc -o webkit webkit.c $(pkg-config --cflags --libs webkit2gtk-4.0)
