#include <qdma.h>

int main()
{
    qdma_handle_t handle;
    qdma_channel_t channel;
    qdma_transfer_t transfer;
    void *buf;

    /* Initialize the QDMA library */
    qdma_init();

    /* Create a QDMA handle */
    handle = qdma_create_handle("your_qdma_device", NULL);
    if (!handle) {
        printf("Failed to create QDMA handle\n");
        return -1;
    }

    /* Create a QDMA channel */
    channel = qdma_create_channel(handle, QDMA_CHANNEL_DIRECTION_MEM_TO_DEV);
    if (!channel) {
        printf("Failed to create QDMA channel\n");
        return -1;
    }

    /* Allocate a buffer for the DMA transfer */
    buf = malloc(1024);
    /* Set up the DMA transfer */
    transfer.src_addr = buf;
    transfer.dst_addr = 0x10000000; /* Replace with your device's address */
    transfer.size = 1024;

    /* Start the DMA transfer */
    qdma_start_transfer(channel, &transfer);

    /* Wait for the DMA transfer to complete */
    qdma_wait_for_transfer(channel, &transfer);

    /* Clean up */
    free(buf);
    qdma_destroy_channel(channel);
    qdma_destroy_handle(handle);

    return 0;
}
