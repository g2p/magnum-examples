#version 330
#define CORRECTION_TEXTURE_SIZE 1024

uniform sampler2D textureData;
uniform samplerBuffer correctionTextureData;

in vec2 textureCoords;

out vec4 original;
out vec4 grayscale;
out vec4 corrected;

void main() {
    /* Original color */
    vec4 color = texture(textureData, textureCoords);
    original = color;

    /* Grayscale */
    float gray = dot(color.rgb, vec3(0.3, 0.59, 0.11));
    grayscale = vec4(gray, gray, gray, 1.0);

    /* Color corrected */
    corrected.r = texelFetch(correctionTextureData, int(color.r*CORRECTION_TEXTURE_SIZE-1)).r;
    corrected.g = texelFetch(correctionTextureData, int(color.g*CORRECTION_TEXTURE_SIZE-1)).r;
    corrected.b = texelFetch(correctionTextureData, int(color.b*CORRECTION_TEXTURE_SIZE-1)).r;
}