#include "ChunkRenderer.h"

#include "../World/Chunk/ChunkMesh.h"
#include "../World/Block/BlockDatabase.h"

#include "../Camera.h"

void ChunkRenderer::add(const ChunkMesh& mesh)
{

}

void ChunkRenderer::render(const Camera& camera)
{
    glEnable(GL_CULL_FACE);
    m_shader.useProgram();
    BlockDatabase::get().textureAtlas.bindTexture();

    m_shader.loadProjectionViewMatrix(camera.getProjectionViewMatrix());

    for (const ChunkMesh* mesh : m_chunks)
    {
        const ChunkMesh& m = *mesh;

        m.getModel().bindVAO();
        glDrawElements(GL_TRIANGLES, m.getModel().getIndicesCount(), GL_UNSIGNED_BYTE, nullptr);
    }
}