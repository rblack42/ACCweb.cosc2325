# TDD Project Makefile Template

# include standard project definitions
include ~/_lib/Make/Makefile_dirs.mak

# this is the set of objects we are building
PGM_APP		= $(BUILD_DIR)/app
TEST_APP	= $(BUILD_DIR)/testapp
MOCK_LIB	= $(BUILD_DIR)/MOCKlib.a
PROD_LIB	= $(BUILD_DIR)/lib.a

# add local directories to include search path
CFLAGS = -Iinclude

# build the project objects
.PHONY:
all:  $(PGM_APP) $(TEST_APP) $(MOCK_LIB)

# include dependency rules
include ~/_lib/Make/Makefile_deps.mak

# include build rules
include ~/_lib/Make/Makefile_build.mak

# build rules for applications
$(PGM_APP):		$(PGM_OBJS) $(PROD_LIB)
	g++ -o $@ $^ $(PROD_LIB)

$(TEST_APP):	$(TEST_OBJS) $(MOCK_LIB)
	g++ -o $@  $^ $(MOCK_LIB)

# clean all constructed objects
.PHONY:
clean:
	rm -f $(PGM_OBJS) $(TEST_OBJS) $(MOCK_OBJS) $(PROD_LIB) $(MOCK_LIB)

# add debugging rules to check file lists
include ~/_lib/Make/Makefile_debug.mak
