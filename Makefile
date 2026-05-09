.PHONY: all q1 q2 arvore-hash clean

all: q1 q2 arvore-hash

q1:
	$(MAKE) -C q1

q2:
	$(MAKE) -C q2

arvore-hash:
	$(MAKE) -C arvore-hash

clean:
	$(MAKE) -C q1 clean
	$(MAKE) -C q2 clean
	$(MAKE) -C arvore-hash clean
