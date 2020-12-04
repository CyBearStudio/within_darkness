#include "Widgets/VBoxLayout.h"


VBoxLayout::VBoxLayout(float offset, Anchors::Flags anchor) : Widget(anchor), mOffset(offset)
{
    
}

sf::FloatRect VBoxLayout::getBoundingRect() const 
{
    
}

void VBoxLayout::setOffset(float offset) 
{
    if (offset != mOffset)
    {
        // set new offset
        mOffset = offset;

        // update children transform
        transformChildren();
    }
}

void VBoxLayout::transformChildren() 
{
    
}
