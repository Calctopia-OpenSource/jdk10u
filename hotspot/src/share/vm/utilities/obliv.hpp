/*
 * Copyright (c) 2021 Calctopia and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.  Oracle designates this
 * particular file as subject to the "Classpath" exception as provided
 * by Oracle in the LICENSE file that accompanied this code.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#ifndef SHARE_VM_UTILITIES_OBLIV_HPP
#define SHARE_VM_UTILITIES_OBLIV_HPP

template<class E> class GrowableArray;

class Obliv : public CHeapObj<mtInternal> {
 public:
  enum TYPE { INT, LONG, FLOAT, DOUBLE, CHAR, BOOL, SHORT };

 private:
  union {
    oint i;
    olong l; // long long as Java long is 64 bits
    ofloat32 f;
    ofloat64 d;
    ochar c;
    oflag b;
    oshort s;
  } _uval;
  TYPE type;
  int _party;
  bool initialized;

 public:
  Obliv() : initialized(false) {}

  Obliv(oint io, TYPE t) : initialized(true) { 
        switch (t) {
                case Obliv::INT:
                        type = Obliv::INT;
                        _uval.i = io;
                break;
                case Obliv::FLOAT:
                        type = Obliv::FLOAT;
                        _uval.f = io;
                break;
        }
  }
  Obliv(olong iol, TYPE t) : initialized(true) { 
	switch (t) {
		case Obliv::LONG:
			type = Obliv::LONG;
			_uval.l = iol;
		break;
		case Obliv::DOUBLE:
			type = Obliv::DOUBLE;
			_uval.d = iol;
		break;
	}
  }
  Obliv(ochar ioc) : initialized(true), type(CHAR) { _uval.c = ioc; }
  Obliv(oflag iob) : initialized(true), type(BOOL) { _uval.b = iob; }
  Obliv(oshort ios) : initialized(true), type(SHORT) { _uval.s = ios; }

  Obliv(oint io, int party, TYPE t) : _party(party), initialized(true) {
        switch (t) {
                case Obliv::INT:
                        type = Obliv::INT;
                        _uval.i = io;
                break;
                case Obliv::FLOAT:
                        type = Obliv::FLOAT;
                        _uval.f = io;
                break;
        }
  }
  Obliv(olong iol, int party, TYPE t) :  _party(party), initialized(true) {
        switch (t) {
                case Obliv::LONG:
                        type = Obliv::LONG;
                        _uval.l = iol;
                break;
                case Obliv::DOUBLE:
                        type = Obliv::DOUBLE;
                        _uval.d = iol;
                break;
        }
  }
  Obliv(ochar ioc, int party) : _party(party), initialized(true), type(CHAR) { _uval.c = ioc; }
  Obliv(oflag iob, int party) : _party(party), initialized(true), type(BOOL) { _uval.b = iob; }
  Obliv(oshort ios, int party) : _party(party), initialized(true), type(SHORT) { _uval.s = ios; }

 oint getInt() { return _uval.i; }

 olong getLong() { return _uval.l; }

 ofloat32 getFloat() { return _uval.f; }

 ofloat64 getDouble() { return _uval.d; }

 ochar getChar() { return _uval.c; }

 oflag getBool() { return _uval.b; }

 oshort getShort() { return _uval.s; }

 void setI (oint io) { _uval.i = io; initialized = true; type = INT; }

 void setF (ofloat32 io) { _uval.f = io; initialized = true; type = FLOAT; }

 void setL (olong io) { _uval.l = io; initialized = true; type = LONG; }

 void setD (ofloat64 io) { _uval.d = io; initialized = true; type = DOUBLE; }

 void set (ochar io) { _uval.c = io; initialized = true; type = CHAR; }

 void set (oflag io) { _uval.b = io; initialized = true; type = BOOL; }

 void set (oshort io) { _uval.s = io; initialized = true; type = SHORT; }

 int getType() { return type; }

 int getParty() { return _party; }

 void setParty (int party) { _party = party; initialized = true; }

 bool isInitialized() { return initialized; }

};



class OblivContainer : public CHeapObj<mtInternal> {

 public:
  enum TYPE { OBLIV, ARRAY_OBLIV };

 private:
  union {
    //Obliv* o;
    GrowableArray<Obliv>* arro;
  } _uc;
  Obliv o;
  TYPE type;
  bool initialized;

 public:
  OblivContainer() : initialized(false) {}

  //OblivContainer(Obliv* io) : initialized(true), type(OBLIV) { o = io; }
  OblivContainer(Obliv io) : initialized(true), type(OBLIV) { o = io; }

  OblivContainer(GrowableArray<Obliv>* iarro) : initialized(true), type(ARRAY_OBLIV) { _uc.arro = iarro; }

  //Obliv* getObliv() { return o; }
  Obliv getObliv() { return o; }

  GrowableArray<Obliv>* getOblivArray() { return _uc.arro; }

  //void setObliv(Obliv* io) { _uc.o = io; initialized = true; }
  void setObliv(Obliv io) { o = io; initialized = true; }

  void setOblivArray(GrowableArray<Obliv>* iarro) { _uc.arro = iarro; initialized = true; }

  int getType() { return type; }

  bool isInitialized() { return initialized; }
};

#endif
