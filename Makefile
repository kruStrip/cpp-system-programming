CMAKE=cmake
SOURCE_DIR=$(abspath $(shell pwd))
BUILD_DIR=$(SOURCE_DIR)/build

all:: build install

build: $(SOURCE_DIR)/CMakeLists.txt
	$(CMAKE) -S $(SOURCE_DIR) -B $(BUILD_DIR)
	make -C $(BUILD_DIR)

install: $(BUILD_DIR)
	make -C $(BUILD_DIR) install

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all build clean
