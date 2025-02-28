name=velocifare
cc=gcc
flags=-Wall -Werror -Wextra -O3 -Ofast -ffast-math
build = build
build.mkdir = if [ ! -d $(build) ];then mkdir $(build);fi
objects = $(build)/obj
objects.mkdir = if [ ! -d $(objects) ];then mkdir $(objects);fi
server = $(wildcard server/*.c)
server.o = $(patsubst %.c, $(objects)/%.o, $(server))
server.mkdir = if [ ! -d $(objects)/server ];then mkdir $(objects)/server;fi
views = $(wildcard views/*.c)
views.o = $(patsubst %.c, $(objects)/%.o, $(views))
views.mkdir = if [ ! -d $(objects)/views ];then mkdir $(objects)/views;fi
static = $(wildcard views/static/*.c)
static.o = $(patsubst %.c, $(objects)/%.o, $(static))
static.mkdir = if [ ! -d $(objects)/views/static ];then mkdir $(objects)/views/static;fi
routes = $(wildcard routes/*.c)
routes.o = $(patsubst %.c, $(objects)/%.o, $(routes))
routes.mkdir = if [ ! -d $(objects)/routes ];then mkdir $(objects)/routes;fi
controllers = $(wildcard controllers/*.c)
controllers.o = $(patsubst %.c, $(objects)/%.o, $(controllers))
controllers.mkdir = if [ ! -d $(objects)/controllers ];then mkdir $(objects)/controllers;fi
middleware = $(wildcard middleware/*.c)
middleware.o = $(patsubst %.c, $(objects)/%.o, $(middleware))
middleware.mkdir = if [ ! -d $(objects)/middleware ];then mkdir $(objects)/middleware;fi

$(objects)/%.o: %.c
	@$(build.mkdir)
	@$(objects.mkdir)
	@$(server.mkdir)
	@$(views.mkdir)
	@$(static.mkdir)
	@$(routes.mkdir)
	@$(controllers.mkdir)
	@$(middleware.mkdir)
	$(cc) $(flags) -c -o $@ $<

$(name): $(server.o) $(views.o) $(static.o) $(routes.o) $(controllers.o) $(middleware.o)
	$(cc) $(flags) -o $@ $^
	strip $(name)

js:
	@npm run build --prefix dev
	@./compile.sh

build:
	@make js
	@make

rebuild: build
	@make -B build

work: 
	vim `fzf`
	@make rebuild
	./$(name)

clean:
	rm -r $(build) $(name)
	rm -r dev/build
