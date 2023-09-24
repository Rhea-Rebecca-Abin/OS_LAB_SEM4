#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX_BLOCKS 100

struct FileBlock {
    char data[512]; // Simulating a block of data
};

struct IndexedFile {
    int index[MAX_BLOCKS]; // Index table
    int num_blocks;       // Number of data blocks
    struct FileBlock blocks[MAX_BLOCKS]; // Data blocks
};

void initializeIndexedFile(struct IndexedFile *file) {
    file->num_blocks = 0;
    for (int i = 0; i < MAX_BLOCKS; i++) {
        file->index[i] = -1; // Initialize all index entries to -1 (unused)
    }
}

int allocateBlock(struct IndexedFile *file) {
    if (file->num_blocks >= MAX_BLOCKS) {
        printf("File is full, cannot allocate more blocks.\n");
        return -1;
    }

    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (file->index[i] == -1) {
            file->index[i] = file->num_blocks;
            file->num_blocks++;
            return i; // Return the block number
        }
    }

    return -1; // No free block found
}

void writeFileBlock(struct IndexedFile *file, int block_number, const char *data) {
    if (block_number >= 0 && block_number < file->num_blocks) {
        strncpy(file->blocks[block_number].data, data, sizeof(file->blocks[block_number].data));
        printf("Data written to block %d: %s\n", block_number, data);
    } else {
        printf("Invalid block number.\n");
    }
}

void readFileBlock(struct IndexedFile *file, int block_number) {
    if (block_number >= 0 && block_number < file->num_blocks) {
        printf("Data in block %d: %s\n", block_number, file->blocks[block_number].data);
    } else {
        printf("Invalid block number.\n");
    }
}

int main() {
    struct IndexedFile file;
    initializeIndexedFile(&file);

    int block1 = allocateBlock(&file);
    int block2 = allocateBlock(&file);

    if (block1 != -1) {
        writeFileBlock(&file, block1, "This is block 1 data.");
    }

    if (block2 != -1) {
        writeFileBlock(&file, block2, "This is block 2 data.");
    }

    readFileBlock(&file, block1);
    readFileBlock(&file, block2);

    return 0;
}

