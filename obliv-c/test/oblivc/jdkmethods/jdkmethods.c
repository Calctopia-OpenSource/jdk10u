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


#include<obliv.h>
#include<stdio.h>
#include<time.h>

#include"../common/util.h"
#include"jdkmethods.h"

double lap;

int main(int argc,char* argv[])
{ 
  ProtocolDesc pd;
  protocolIO64 io;

  if(argc<3)
  {
    if(argc<2) fprintf(stderr,"Port number missing\n");
    else if(argc<3) fprintf(stderr,"Party missing\n");
    else fprintf(stderr,"number missing\n");
    fprintf(stderr,"Usage: %s <port> <1|2> <number>\n",argv[0]);
    fprintf(stderr,"  Party 1 provides float64 in long long format\n");
    fprintf(stderr,"  Party 2 provides float64 in long long format\n");
    return 1;
  }

  int i, party = (argv[2][0]=='1'?1:2);
  io.party = party;

  ocTestUtilTcpOrDie(&pd,party==1,argv[1]);

  if(argc >= 4) {
      sscanf(argv[3],"%llX",&io.input);
      io.partySetInput = true;
  } else {
      io.partySetInput = false;
  }

  setCurrentParty(&pd, party);
  lap = wallClock();
  execYaoProtocol(&pd, goadd, &io);

  fprintf(stderr,"Total time: %lf s\n",wallClock()-lap);
  cleanupProtocol(&pd);
  fprintf(stderr,"\n");

  return 0;
}
