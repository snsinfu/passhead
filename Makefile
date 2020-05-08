CFLAGS = \
  -std=c99 \
  -Wpedantic \
  -Wall \
  -Wextra \
  -Wconversion \
  -D_POSIX_C_SOURCE=200112L \
  -O2

.PHONY: all clean

all: passhead
	@:

clean:
	rm -f passhead

passhead: main.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
