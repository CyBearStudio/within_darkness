#ifndef HBOXLAYOUT_H_INCLUDED
#define HBOXLAYOUT_H_INCLUDED

#include "Widgets/Widget.h"


class HBoxLayout : public Widget
{
public:
    HBoxLayout(float offset = 0.f, Anchors::Flags anchor = Anchors::Default);
    virtual sf::FloatRect getBoundingRect() const override;
    void setOffset(float offset);

private:
    virtual void onDraw(sf::RenderTarget& target, sf::RenderStates states) const override;
    virtual void onUpdateTransform() override;
    float mOffset;
};

#endif // HBOXLAYOUT_H_INCLUDED