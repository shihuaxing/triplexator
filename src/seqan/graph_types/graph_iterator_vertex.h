// ==========================================================================
//                 SeqAn - The Library for Sequence Analysis
// ==========================================================================
// Copyright (c) 2006-2010, Knut Reinert, FU Berlin
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of Knut Reinert or the FU Berlin nor the names of
//       its contributors may be used to endorse or promote products derived
//       from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL KNUT REINERT OR THE FU BERLIN BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
// OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
// DAMAGE.
//
// ==========================================================================

#ifndef SEQAN_HEADER_GRAPH_ITERATOR_VERTEX_H
#define SEQAN_HEADER_GRAPH_ITERATOR_VERTEX_H

namespace SEQAN_NAMESPACE_MAIN
{

//////////////////////////////////////////////////////////////////////////////
// Graph VertexIterator
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////

/**
.Spec.Vertex Iterator:
..cat:Graph
..summary:Vertex iterator for @Class.Graph@.
..signature:Iterator<TGraph, VertexIterator>
..param.TGraph:A graph.
...type:Class.Graph
..general:Class.Iter
..see:Spec.Edge Iterator
..see:Spec.Out-Edge Iterator
..see:Spec.Adjacency Iterator
..see:Spec.Bfs Iterator
..see:Spec.Dfs Preorder Iterator
..include:seqan/graph_types.h

.Memfunc.Vertex Iterator#Iter
..summary:Constructor
..class:Spec.Vertex Iterator
..signature:Iter()
..signature:Iter(graph)
..signature:Iter(iter)
..param.graph:The graph to iterate vertices of.
...type:Class.Graph
..param.iter:Other iterator to copy-construct from.
...type:Spec.Vertex Iterator
*/
template<typename TGraph, typename TSpec>
class Iter<TGraph, GraphIterator<InternalVertexIterator<TSpec> > > 
{
public:
	typedef typename VertexDescriptor<TGraph>::Type TVertexDescriptor_;
	TGraph const* data_host;
	TVertexDescriptor_ data_pos;

	Iter()	
	{
		SEQAN_CHECKPOINT
	}
	
	Iter(TGraph const& _graph) : 
		data_host(&_graph), 
		data_pos(getIdLowerBound(_getVertexIdManager(*data_host))) 
	{
		SEQAN_CHECKPOINT
	}

	Iter(Iter const& _iter) : 
		data_host(_iter.data_host), 
		data_pos(_iter.data_pos) 
	{
		SEQAN_CHECKPOINT
	}

	~Iter() {
		SEQAN_CHECKPOINT
	}

	Iter const&	operator = (Iter const & _other) {
		SEQAN_CHECKPOINT
		if (this == &_other) return *this;
		data_host = _other.data_host;
		data_pos = _other.data_pos;
		return *this;
	}
//____________________________________________________________________________
};

//////////////////////////////////////////////////////////////////////////////
// Graph InternalVertexIterator - Metafunctions
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////

///.Metafunction.Iterator.param.T.type:Class.Graph

template<typename TGraph>
struct Iterator<TGraph, VertexIterator>
{	
	typedef Iter<TGraph, GraphIterator<InternalVertexIterator<VertexIterator> > > Type;
};

template<typename TGraph>
struct Iterator<TGraph const, VertexIterator>
{	
	typedef Iter<TGraph const, GraphIterator<InternalVertexIterator<VertexIterator> > > Type;
};

//////////////////////////////////////////////////////////////////////////////

template<typename TGraph, typename TIteratorSpec>
struct Value<Iter<TGraph, GraphIterator<InternalVertexIterator<TIteratorSpec> > > >
{
	typedef typename VertexDescriptor<TGraph>::Type Type;
};

template<typename TGraph, typename TIteratorSpec>
struct Value<Iter<TGraph const, GraphIterator<InternalVertexIterator<TIteratorSpec> > > >
{
	typedef typename VertexDescriptor<TGraph const>::Type Type;
};

//////////////////////////////////////////////////////////////////////////////

template<typename TGraph, typename TIteratorSpec>
struct Reference<Iter<TGraph, GraphIterator<InternalVertexIterator<TIteratorSpec> > > >
{
	typedef typename Value<Iter<TGraph, GraphIterator<InternalVertexIterator<TIteratorSpec> > > >::Type& Type;
};

template<typename TGraph, typename TIteratorSpec>
struct Reference<Iter<TGraph const, GraphIterator<InternalVertexIterator<TIteratorSpec> > > >
{
	typedef typename Value<Iter<TGraph const, GraphIterator<InternalVertexIterator<TIteratorSpec> > > >::Type& Type;
};

//////////////////////////////////////////////////////////////////////////////

template<typename TGraph, typename TIteratorSpec>
struct GetValue<Iter<TGraph, GraphIterator<InternalVertexIterator<TIteratorSpec> > > >
{
	typedef typename Value<Iter<TGraph, GraphIterator<InternalVertexIterator<TIteratorSpec> > > >::Type Type;
};

template<typename TGraph, typename TIteratorSpec>
struct GetValue<Iter<TGraph const, GraphIterator<InternalVertexIterator<TIteratorSpec> > > >
{
	typedef typename Value<Iter<TGraph const, GraphIterator<InternalVertexIterator<TIteratorSpec> > > >::Type Type;
};

//////////////////////////////////////////////////////////////////////////////

template<typename TGraph, typename TIteratorSpec>
struct Spec<Iter<TGraph, GraphIterator<InternalVertexIterator<TIteratorSpec> > > >
{
	typedef TIteratorSpec Type;
};

template<typename TGraph, typename TIteratorSpec>
struct Spec<Iter<TGraph const, GraphIterator<InternalVertexIterator<TIteratorSpec> > > >
{
	typedef TIteratorSpec Type;
};


//////////////////////////////////////////////////////////////////////////////
// Graph InternalVertexIterator - FUNCTIONS
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////

/**
.Function.getValue:
..cat:Graph
..param.object
...type:Spec.Vertex Iterator
...type:Spec.Out-Edge Iterator
...type:Spec.Edge Iterator
...type:Spec.Adjacency Iterator
...type:Spec.Bfs Iterator
...type:Spec.Dfs Preorder Iterator
..include:seqan/graph_types.h
*/

template<typename TGraph, typename TSpec>
inline typename GetValue<Iter<TGraph, GraphIterator<InternalVertexIterator<TSpec> > > >::Type
getValue(Iter<TGraph, GraphIterator<InternalVertexIterator<TSpec> > >& it)
{
SEQAN_CHECKPOINT
	return it.data_pos;
}

//////////////////////////////////////////////////////////////////////////////

/**
.Function.value:
..cat:Graph
..param.object
...type:Spec.Vertex Iterator
...type:Spec.Out-Edge Iterator
...type:Spec.Edge Iterator
...type:Spec.Adjacency Iterator
...type:Spec.Bfs Iterator
...type:Spec.Dfs Preorder Iterator
..include:seqan/graph_types.h
*/

template<typename TGraph, typename TSpec>
inline typename Reference<Iter<TGraph, GraphIterator<InternalVertexIterator<TSpec> > > >::Type
value(Iter<TGraph, GraphIterator<InternalVertexIterator<TSpec> > >& it)
{
SEQAN_CHECKPOINT
	return it.data_pos;
}

//////////////////////////////////////////////////////////////////////////////

template<typename TGraph, typename TSpec>
inline typename Reference<Iter<TGraph, GraphIterator<InternalVertexIterator<TSpec> > > >::Type
operator * (Iter<TGraph, GraphIterator<InternalVertexIterator<TSpec> > >& it)
{
	SEQAN_CHECKPOINT
	return value(it);
}

//////////////////////////////////////////////////////////////////////////////

/**
.Function.hostGraph:
..cat:Graph
..summary:The graph this iterator is working on.
..signature:hostGraph(it)
..param.it:A vertex or edge iterator.
...type:Spec.Vertex Iterator
...type:Spec.Out-Edge Iterator
...type:Spec.Edge Iterator
...type:Spec.Adjacency Iterator
...type:Spec.Bfs Iterator
...type:Spec.Dfs Preorder Iterator
..returns:A pointer to the host graph.
..include:seqan/graph_types.h
*/

template<typename TGraph, typename TSpec>
inline typename Host<Iter<TGraph, GraphIterator<InternalVertexIterator<TSpec> > > >::Type const&
hostGraph(Iter<TGraph, GraphIterator<InternalVertexIterator<TSpec> > >& it)
{
	SEQAN_CHECKPOINT
	return *it.data_host;
} 

//////////////////////////////////////////////////////////////////////////////

/**
.Function.atBegin:
..cat:Graph
..param.iterator
...type:Spec.Vertex Iterator
...type:Spec.Out-Edge Iterator
...type:Spec.Edge Iterator
...type:Spec.Adjacency Iterator
...type:Spec.Bfs Iterator
...type:Spec.Dfs Preorder Iterator
..see:Function.goBegin
..include:seqan/graph_types.h
*/

template<typename TGraph, typename TSpec>
inline bool
atBegin(Iter<TGraph, GraphIterator<InternalVertexIterator<TSpec> > >& it)
{
SEQAN_CHECKPOINT
	return (getValue(it) == getIdLowerBound(_getVertexIdManager(*it.data_host)));	
}

//////////////////////////////////////////////////////////////////////////////

/**
.Function.goBegin:
..cat:Graph
..param.iterator
...type:Spec.Vertex Iterator
...type:Spec.Out-Edge Iterator
...type:Spec.Edge Iterator
...type:Spec.Adjacency Iterator
...type:Spec.Bfs Iterator
...type:Spec.Dfs Preorder Iterator
..include:seqan/graph_types.h
*/

template<typename TGraph, typename TSpec>
inline void
goBegin(Iter<TGraph, GraphIterator<InternalVertexIterator<TSpec> > >& it)
{
	SEQAN_CHECKPOINT
	it.data_pos = getIdLowerBound(_getVertexIdManager(*it.data_host));
}

//////////////////////////////////////////////////////////////////////////////

/**
.Function.atEnd:
..cat:Graph
..param.iterator
...type:Spec.Vertex Iterator
...type:Spec.Out-Edge Iterator
...type:Spec.Edge Iterator
...type:Spec.Adjacency Iterator
...type:Spec.Bfs Iterator
...type:Spec.Dfs Preorder Iterator
..see:Function.goEnd
..include:seqan/graph_types.h
*/

template<typename TGraph, typename TSpec>
inline bool
atEnd(Iter<TGraph, GraphIterator<InternalVertexIterator<TSpec> > >& it)
{
SEQAN_CHECKPOINT
	return (getValue(it) >= getIdUpperBound(_getVertexIdManager(*it.data_host)));	
}

//////////////////////////////////////////////////////////////////////////////

/**
.Function.goEnd:
..cat:Graph
..param.iterator
...type:Spec.Vertex Iterator
...type:Spec.Out-Edge Iterator
...type:Spec.Edge Iterator
...type:Spec.Adjacency Iterator
...type:Spec.Bfs Iterator
...type:Spec.Dfs Preorder Iterator
..include:seqan/graph_types.h
*/
template<typename TGraph, typename TSpec>
inline void
goEnd(Iter<TGraph, GraphIterator<InternalVertexIterator<TSpec> > >& it)
{
	SEQAN_CHECKPOINT
	it.data_pos = getIdUpperBound(_getVertexIdManager(*it.data_host));
}

//////////////////////////////////////////////////////////////////////////////

/**
.Function.goNext:
..cat:Graph
..param.iterator
...type:Spec.Vertex Iterator
...type:Spec.Out-Edge Iterator
...type:Spec.Edge Iterator
...type:Spec.Adjacency Iterator
...type:Spec.Bfs Iterator
...type:Spec.Dfs Preorder Iterator
..include:seqan/graph_types.h
*/

template<typename TGraph, typename TSpec>
inline void
goNext(Iter<TGraph, GraphIterator<InternalVertexIterator<TSpec> > >& it)
{
	SEQAN_CHECKPOINT
	if (!atEnd(it)) ++it.data_pos;
	while ((!atEnd(it)) && (!idInUse(_getVertexIdManager(*it.data_host), it.data_pos))) ++it.data_pos;
}

//////////////////////////////////////////////////////////////////////////////

template<typename TGraph, typename TSpec>
inline Iter<TGraph, GraphIterator<InternalVertexIterator<TSpec> > >&
operator ++(Iter<TGraph, GraphIterator<InternalVertexIterator<TSpec> > >& it)
{
SEQAN_CHECKPOINT
	goNext(it);
	return it;
}

//////////////////////////////////////////////////////////////////////////////

template<typename TGraph, typename TSpec>
inline Iter<TGraph, GraphIterator<InternalVertexIterator<TSpec> > >
operator ++(Iter<TGraph, GraphIterator<InternalVertexIterator<TSpec> > >& it, int)
{
	SEQAN_CHECKPOINT
	Iter<TGraph, GraphIterator<InternalVertexIterator<TSpec> > > ret = it;
	goNext(it);
	return ret;
}

//////////////////////////////////////////////////////////////////////////////

/**
.Function.goPrevious:
..cat:Graph
..param.iterator
...type:Spec.Vertex Iterator
...type:Spec.Out-Edge Iterator
...type:Spec.Edge Iterator
...type:Spec.Adjacency Iterator
..include:seqan/graph_types.h
*/

template<typename TGraph, typename TSpec>
inline void
goPrevious(Iter<TGraph, GraphIterator<InternalVertexIterator<TSpec> > >& it)
{
	SEQAN_CHECKPOINT
	if (!atBegin(it)) --it.data_pos;
	while ((!atBegin(it)) && (!idInUse(_getVertexIdManager(*it.data_host), it.data_pos))) --it.data_pos;
}

//////////////////////////////////////////////////////////////////////////////

template<typename TGraph, typename TSpec>
inline Iter<TGraph, GraphIterator<InternalVertexIterator<TSpec> > >&
operator --(Iter<TGraph, GraphIterator<InternalVertexIterator<TSpec> > >& it)
{
SEQAN_CHECKPOINT
	goPrevious(it);
	return it;
}

//////////////////////////////////////////////////////////////////////////////

template<typename TGraph, typename TSpec>
inline Iter<TGraph, GraphIterator<InternalVertexIterator<TSpec> > >
operator --(Iter<TGraph, GraphIterator<InternalVertexIterator<TSpec> > >& it, int)
{
	SEQAN_CHECKPOINT
	Iter<TGraph, GraphIterator<InternalVertexIterator<TSpec> > > ret = it;
	goPrevious(it);
	return ret;
}

//////////////////////////////////////////////////////////////////////////////

template<typename TGraph, typename TSpec>
inline bool
operator ==(Iter<TGraph, GraphIterator<InternalVertexIterator<TSpec> > >& it1,
			Iter<TGraph, GraphIterator<InternalVertexIterator<TSpec> > >& it2)
{
	SEQAN_CHECKPOINT
	return (it1.data_pos==it2.data_pos);
}

//////////////////////////////////////////////////////////////////////////////

template<typename TGraph, typename TSpec>
inline bool
operator !=(Iter<TGraph, GraphIterator<InternalVertexIterator<TSpec> > >& it1,
			Iter<TGraph, GraphIterator<InternalVertexIterator<TSpec> > >& it2)
{
	SEQAN_CHECKPOINT
	return (it1.data_pos!=it2.data_pos);
}

}// namespace SEQAN_NAMESPACE_MAIN

#endif //#ifndef SEQAN_HEADER_...
