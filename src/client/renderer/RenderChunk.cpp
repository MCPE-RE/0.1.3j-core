#include "RenderChunk.h"
 
uint32_t RenderChunk::runningId = 0;
 
RenderChunk::RenderChunk() {
    this->bufferId = -1;
    this->addedVertices = 0;
    this->id = ++RenderChunk::runningId;
}
 
RenderChunk::RenderChunk(uint32_t bufferId, uint32_t addedVertices) {
    this->bufferId = bufferId;
    this->addedVertices = addedVertices;
    this->id = ++RenderChunk::runningId;
}
