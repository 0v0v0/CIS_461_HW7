#include "diffusearealight.h"

Color3f DiffuseAreaLight::L(const Intersection &isect, const Vector3f &w) const
{
    //TODO

    if(twoSided)
    {
        return emittedLight;
    }
    else if( glm::dot(isect.normalGeometric, w) > 0)
    {
        return emittedLight;
    }

    return glm::vec3(0);

}

Color3f DiffuseAreaLight::Sample_Li(const Intersection &ref, const Point2f &xi,
                                    Vector3f *wi, Float *pdf, Vector3f *point) const
{
    //Generate intersection
    Intersection pShape = shape->Sample(ref, xi, pdf);

    *point=pShape.point;

    //pShape.mediumInterface = mediumInterface;

    if (*pdf == 0 || glm::length(pShape.point - ref.point) == 0)
    {
        *pdf = 0;
        return Color3f(0);
    }
    *wi = glm::normalize(pShape.point - ref.point);


    return L(pShape, -*wi);
}

float DiffuseAreaLight::Pdf_Li(const Intersection &ref, const Vector3f &wi) const
{
    Ray ray = ref.SpawnRay(wi);
    Float tHit;
    Intersection isectLight;
    // Ignore any alpha textures used for trimming the shape when performing
    // this intersection. Hack for the "San Miguel" scene, where this is used
    // to make an invisible area light.

    if(!shape->Intersect(ray,&isectLight))
    {
        return 0;
    }

    // Convert light sample weight to solid angle measure
    Float pdf = glm::length2(ref.point - isectLight.point) / (AbsDot(isectLight.normalGeometric, -wi) * shape->Area());
    if (std::isinf(pdf))
    {
        pdf = 0.f;
    }
    return pdf;
}

