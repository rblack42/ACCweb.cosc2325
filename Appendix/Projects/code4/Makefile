DIRS    = lib src

all:
		for dir in $(DIRS); do  \
			($(MAKE) -C $$dir all); \
		done

clean:
		for dir in $(DIRS); do  \
			($(MAKE) -C $$dir clean); \
		done

run:
		$(MAKE) -C src run

