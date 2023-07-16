
vec3 palette(float dist)
{
    vec3 a = vec3(0.640, 0.640, 0.768);
    vec3 b = vec3(0.788, 0.302, -0.200);
    ///vec3 c = vec3(-0.379, 0.700, 0.700);
    vec3 c = vec3(-0.758, 1.400, 1.400);
    vec3 d = vec3(1.427, 0.627, -0.693);
    ///vec3 a = vec3(0.5, 0.5, 0.5);
    ///vec3 b = vec3(0.5, 0.5, 0.5);
    ///vec3 c = vec3(1.0, 1.0, 1.0);
    ///vec3 d = vec3(0.263, 0.416, 0.557);
    
    return a + b * cos(6.28318*(c*dist+d));
}


void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
    
    vec2 center = iResolution.xy / 2.0;
    
    float dist = length(fragCoord - center);
    
    vec3 rgb = palette(dist / length(center) + iTime);
    
    float color = sin((dist / 100.0) + iTime);
    
    color = abs(color);
    color = 0.05 / color;
    
    vec3 white = vec3(1.0, 1.0, 1.0);
    
    fragColor = vec4(rgb*color, 1.);
}