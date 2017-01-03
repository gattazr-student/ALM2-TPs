COB=./s_to_ob.pl


OB_DIR=ob/
MOB_DIR=mob/

OB_FILES:=$(patsubst %.s,$(OB_DIR)%.ob,$(wildcard *.s))
MOB_FILES:=$(patsubst %.muc,$(MOB_DIR)%.mob,$(wildcard *.muc))



all: $(OB_FILES) $(MOB_FILES)

$(OB_DIR)%.ob: %.s $(COB)
	$(COB) < $< > $@

$(MOB_DIR)%.mob: %.muc
	masm $<
	mv sortie.mob $@

clean:
	$(RM) $(OB_DIR)*.ob
	$(RM) $(MOB_DIR)*.mob
