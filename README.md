sudo docker build --no-cache -t linuxcenv .

sudo docker run --name cpp_container -v $(pwd):/work --rm -it linuxcenv

ls build

build/linux_app