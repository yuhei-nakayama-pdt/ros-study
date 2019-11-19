https://qiita.com/srs/items/5f44440afea0eb616b4a

↑にしたがって勉強していく


# Build

```sh
docker-compose up build
```

# Run

```sh
$ xhost +
$ docker-compose up launch
```

# Copy include to local (for intellisense)

```sh
$ docker cp $(docker-compose images | grep build | cut -d' ' -f1):/usr/include/ .
$ docker cp $(docker-compose images | grep build | cut -d' ' -f1):/opt/ros/kinetic/include/ .
```
