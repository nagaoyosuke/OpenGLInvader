SRC=keyboard.c Manager.c timer.c Player.c keyup.c Invaider.c Bullet.c
OPT=-Wl,-w -Wno-deprecated-declarations -framework OpenGL -framework GLUT

game: $(SRC)
	cc $(SRC) -o game $(OPT)

all: game

