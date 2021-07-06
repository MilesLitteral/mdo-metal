
//mondradiko metal prototype

#include "mtlpp.hpp"

int main()
{
    //Initialize Metal API
    mtlpp::Device device = mtlpp::Device::CreateSystemDefaultDevice();

    mtlpp::CommandQueue commandQueue = device.NewCommandQueue();
    mtlpp::CommandBuffer commandBuffer = commandQueue.CommandBuffer();

    //Create a Box and Triangle on Screen
    mtlpp::TextureDescriptor textureDesc = mtlpp::TextureDescriptor::Texture2DDescriptor(
        mtlpp::PixelFormat::RGBA8Unorm, 320, 240, false);
    textureDesc.SetUsage(mtlpp::TextureUsage::RenderTarget);
    mtlpp::Texture texture = device.NewTexture(textureDesc);

    // Draw the triangle source (Obj-C).
    /*[renderEncoder drawPrimitives:MTLPrimitiveTypeTriangle
                    vertexStart:0
                    vertexCount:3];*/

    mtlpp::renderEncoder render = mtlpp::drawPrimitives::MTLPrimitiveTypeTriangle(0, 3);
    render.SetUsage(mtlpp::drawPrimitives::RenderTarget)

    // ...

    return 0;
}