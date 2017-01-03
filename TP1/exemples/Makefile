
OB_FILES:=$(patsubst %.s,%.ob,$(wildcard *.s))

build-ob: $(OB_FILES)

%.ob: %.s s_to_ob.pl
	./s_to_ob.pl < $< > $@

clean:
	$(RM) *.ob
