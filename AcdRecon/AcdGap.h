#ifndef ACDGAP_H
#define ACDGAP_H

namespace AcdRecon {

  typedef enum { None=0, 
		 SideCornerEdge=1,   
		 TopCornerEdge=2,
		 X_RibbonSide=3, 
		 Y_RibbonSide=4, 
		 Y_RibbonTop=5,
		 TileHole=6,
		 NumGapTypes } AcdGapType;

  typedef enum { Top=0,
		 MinusX,
		 MimusY,
		 PlusX,
		 PluxY,
		 Bottom,
		 NumFaces } AcdFace;

}

#endif
