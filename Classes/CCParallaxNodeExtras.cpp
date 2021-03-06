//
//  Created by Gonzalo Diaz Cruz on 04-09-12.
//  Copyright Studio Pangea 2012. All rights reserved.
//  http://www.studiopangea.com/
//

#include "CCParallaxNodeExtras.h"

// Hack to access CCPointObject (which is not a public class)
class CCPointObject  : CCObject {
    CC_SYNTHESIZE(CCPoint, m_tRatio, Ratio)
    CC_SYNTHESIZE(CCPoint, m_tOffset, Offset)
    CC_SYNTHESIZE(CCNode *,m_pChild, Child)	// weak ref
};

// Need to provide our own constructor
CCParallaxNodeExtras::CCParallaxNodeExtras() {
    CCParallaxNode() ; // call parent constructor
}

CCParallaxNodeExtras * CCParallaxNodeExtras::node() {
    return new CCParallaxNodeExtras() ;
}

void CCParallaxNodeExtras::incrementOffset(CCPoint offset,CCNode* node){
    for( unsigned int i=0;i < m_pParallaxArray->num;i++) {
        CCPointObject *point = (CCPointObject *)m_pParallaxArray->arr[i];
        CCNode * curNode = point->getChild() ;
        if( curNode->isEqual(node) ) {
            point->setOffset( ccpAdd(point->getOffset(), offset) );
            break;
        }
    }
}
