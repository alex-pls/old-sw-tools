	.686p
	ifdef ??version
	if    ??version GT 500H
	.mmx
	endif
	endif
	model flat
	ifndef	??version
	?debug	macro
	endm
	endif
	?debug	S "..\CpuInfo.cpp"
	?debug	T "..\CpuInfo.cpp"
_TEXT	segment dword public use32 'CODE'
_TEXT	ends
_DATA	segment dword public use32 'DATA'
_DATA	ends
_BSS	segment dword public use32 'BSS'
_BSS	ends
DGROUP	group	_BSS,_DATA
_DATA	segment dword public use32 'DATA'
@_$DCOJB$@CpuInfo@$bctr$qxo	segment virtual
	align	2
@@_$DCOJB$@CpuInfo@$bctr$qxo	label	dword
	dd	@@$xt$p7CpuInfo
	dd	5
	dd	8
	dd	0
@_$DCOJB$@CpuInfo@$bctr$qxo	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@_$ECTPJB$@CpuInfo@$bctr$qxo	segment virtual
	align	2
@@_$ECTPJB$@CpuInfo@$bctr$qxo	label	dword
	dd	0
	dd	-36
	dw	0
	dw	5
	dd	0
	dd	@@_$DCOJB$@CpuInfo@$bctr$qxo
	dw	8
	dw	5
	dd	0
	dd	0
	dw	8
	dw	5
	dd	0
	dd	0
@_$ECTPJB$@CpuInfo@$bctr$qxo	ends
_DATA	ends
_TEXT	segment dword public use32 'CODE'
@CpuInfo@$bctr$qxo	segment virtual
	align	2
@@CpuInfo@$bctr$qxo	proc	near
?live16385@0:
@1:
	push      ebp
	mov       ebp,esp
	add       esp,-68
	mov       eax,offset @@_$ECTPJB$@CpuInfo@$bctr$qxo
	push      ebx
	push      esi
	mov       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	call      @__InitExceptBlockLDTC
?live16385@16: ; ESI = &__nullref
	mov       word ptr [ebp-20],8
	mov       edx,offset @@CpuInfo@3+12
	mov       ecx,dword ptr [ebp+8]
	mov       dword ptr [ecx],edx
	mov       eax,dword ptr [ebp+8]
	add       eax,4
	push      eax
	call      @@CpuStats@$bctr$qv
	pop       ecx
	xor       eax,eax
	add       dword ptr [ebp-8],6
	mov       ebx,dword ptr [ebp+8]
	add       ebx,116
	cmp       esi,esi
	mov       edx,ebx
	mov       dword ptr [ebx+8],eax
	lea       eax,dword ptr [esi+12]
	mov       dword ptr [ebx+8],eax
	mov       edx,dword ptr [edx+8]
	mov       dword ptr [ebp-44],edx
	je        short @2
	push      esi
	call      @InterlockedIncrement
@2:
@3:
	inc       dword ptr [ebp-8]
	xor       eax,eax
	mov       ebx,dword ptr [ebp+8]
	add       ebx,132
	cmp       esi,esi
	mov       edx,ebx
	mov       dword ptr [ebx+8],eax
	lea       eax,dword ptr [esi+12]
	mov       dword ptr [ebx+8],eax
	mov       edx,dword ptr [edx+8]
	mov       dword ptr [ebp-60],edx
	je        short @4
	push      esi
	call      @InterlockedIncrement
@4:
@5:
	inc       dword ptr [ebp-8]
?live16385@32: ; 
	push      offset s@
	mov       ecx,dword ptr [ebp+8]
	add       ecx,116
	push      ecx
	call      @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$basg$qpxc
	add       esp,8
	mov       eax,dword ptr [ebp+8]
	push      eax
	mov       edx,dword ptr [eax]
	call      dword ptr [edx+4]
	cmp       byte ptr [ebp+12],0
	pop       ecx
	je        short @6
	mov       ecx,dword ptr [ebp+8]
	push      ecx
	mov       eax,dword ptr [ecx]
	call      dword ptr [eax+8]
	pop       ecx
@6:
	mov       edx,dword ptr [ebp-36]
	mov       dword ptr fs:[0],edx
	mov       eax,dword ptr [ebp+8]
@8:
@7:
	pop       esi
	pop       ebx
	mov       esp,ebp
	pop       ebp
	ret 
@@CpuInfo@$bctr$qxo	endp
@CpuInfo@$bctr$qxo	ends
_TEXT	ends
_DATA	segment dword public use32 'DATA'
@_$DCQJB$@CpuInfo@$bctr$qrx7CpuInfo	segment virtual
	align	2
@@_$DCQJB$@CpuInfo@$bctr$qrx7CpuInfo	label	dword
	dd	@@$xt$p7CpuInfo
	dd	5
	dd	8
	dd	0
@_$DCQJB$@CpuInfo@$bctr$qrx7CpuInfo	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@_$ECTRJB$@CpuInfo@$bctr$qrx7CpuInfo	segment virtual
	align	2
@@_$ECTRJB$@CpuInfo@$bctr$qrx7CpuInfo	label	dword
	dd	0
	dd	-36
	dw	0
	dw	5
	dd	0
	dd	@@_$DCQJB$@CpuInfo@$bctr$qrx7CpuInfo
	dw	8
	dw	5
	dd	0
	dd	0
	dw	8
	dw	5
	dd	0
	dd	0
@_$ECTRJB$@CpuInfo@$bctr$qrx7CpuInfo	ends
_DATA	ends
_TEXT	segment dword public use32 'CODE'
@CpuInfo@$bctr$qrx7CpuInfo	segment virtual
	align	2
@@CpuInfo@$bctr$qrx7CpuInfo	proc	near
?live16389@0:
@9:
	push      ebp
	mov       ebp,esp
	add       esp,-68
	mov       eax,offset @@_$ECTRJB$@CpuInfo@$bctr$qrx7CpuInfo
	push      ebx
	push      esi
	mov       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	call      @__InitExceptBlockLDTC
?live16389@16: ; ESI = &__nullref
	mov       word ptr [ebp-20],8
	mov       edx,offset @@CpuInfo@3+12
	mov       ecx,dword ptr [ebp+8]
	mov       dword ptr [ecx],edx
	mov       eax,dword ptr [ebp+8]
	add       eax,4
	push      eax
	call      @@CpuStats@$bctr$qv
	pop       ecx
	xor       eax,eax
	add       dword ptr [ebp-8],6
	mov       ebx,dword ptr [ebp+8]
	add       ebx,116
	cmp       esi,esi
	mov       edx,ebx
	mov       dword ptr [ebx+8],eax
	lea       eax,dword ptr [esi+12]
	mov       dword ptr [ebx+8],eax
	mov       edx,dword ptr [edx+8]
	mov       dword ptr [ebp-44],edx
	je        short @10
	push      esi
	call      @InterlockedIncrement
@10:
@11:
	inc       dword ptr [ebp-8]
	xor       eax,eax
	mov       ebx,dword ptr [ebp+8]
	add       ebx,132
	cmp       esi,esi
	mov       edx,ebx
	mov       dword ptr [ebx+8],eax
	lea       eax,dword ptr [esi+12]
	mov       dword ptr [ebx+8],eax
	mov       edx,dword ptr [edx+8]
	mov       dword ptr [ebp-60],edx
	je        short @12
	push      esi
	call      @InterlockedIncrement
@12:
@13:
	inc       dword ptr [ebp-8]
?live16389@32: ; 
	mov       ecx,dword ptr [ebp+12]
	push      ecx
	mov       eax,dword ptr [ebp+8]
	push      eax
	mov       edx,dword ptr [eax]
	call      dword ptr [edx+48]
	add       esp,8
	mov       ecx,dword ptr [ebp-36]
	mov       dword ptr fs:[0],ecx
	mov       eax,dword ptr [ebp+8]
@15:
@14:
	pop       esi
	pop       ebx
	mov       esp,ebp
	pop       ebp
	ret 
@@CpuInfo@$bctr$qrx7CpuInfo	endp
@CpuInfo@$bctr$qrx7CpuInfo	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@CpuInfo@$basg$qrx7CpuInfo	segment virtual
	align	2
@@CpuInfo@$basg$qrx7CpuInfo	proc	near
?live16392@0:
@16:
	push      ebp
	mov       ebp,esp
	push      ebx
	mov       eax,dword ptr [ebp+12]
	mov       ebx,dword ptr [ebp+8]
?live16392@16: ; EBX = this, EAX = right
	cmp       eax,ebx
	je        short @17
	push      eax
	push      ebx
	mov       eax,dword ptr [ebx]
	call      dword ptr [eax+48]
	add       esp,8
?live16392@48: ; EBX = this
@17:
	mov       eax,ebx
?live16392@64: ; 
@19:
@18:
	pop       ebx
	pop       ebp
	ret 
@@CpuInfo@$basg$qrx7CpuInfo	endp
@CpuInfo@$basg$qrx7CpuInfo	ends
_TEXT	ends
_DATA	segment dword public use32 'DATA'
@_$DCVJB$@CpuInfo@$bdtr$qv	segment virtual
	align	2
@@_$DCVJB$@CpuInfo@$bdtr$qv	label	dword
	dd	@@$xt$p7CpuInfo
	dd	5
	dd	8
	dd	0
@_$DCVJB$@CpuInfo@$bdtr$qv	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@_$ECTWJB$@CpuInfo@$bdtr$qv	segment virtual
	align	2
@@_$ECTWJB$@CpuInfo@$bdtr$qv	label	dword
	dd	0
	dd	-36
	dw	0
	dw	5
	dd	0
	dd	@@_$DCVJB$@CpuInfo@$bdtr$qv
	dw	8
	dw	5
	dd	0
	dd	0
	dw	8
	dw	5
	dd	0
	dd	0
@_$ECTWJB$@CpuInfo@$bdtr$qv	ends
_DATA	ends
_TEXT	segment dword public use32 'CODE'
@CpuInfo@$bdtr$qv	segment virtual
	align	2
@@CpuInfo@$bdtr$qv	proc	near
?live16393@0:
@20:
	push      ebp
	mov       ebp,esp
	add       esp,-92
	mov       eax,offset @@_$ECTWJB$@CpuInfo@$bdtr$qv
	push      ebx
	push      esi
	push      edi
	call      @__InitExceptBlockLDTC
	mov       dword ptr [ebp-8],8
	cmp       dword ptr [ebp+8],0
	je        @21
	mov       word ptr [ebp-20],8
	mov       edx,offset @@CpuInfo@3+12
	mov       ecx,dword ptr [ebp+8]
	mov       dword ptr [ecx],edx
	dec       dword ptr [ebp-8]
	mov       ebx,dword ptr [ebp+8]
	add       ebx,132
	cmp       dword ptr [ebx+8],0
	je        short @23
	mov       eax,dword ptr [ebx+8]
	mov       edx,dword ptr [eax-12]
	inc       edx
	test      edx,edx
	je        short @26
	mov       esi,dword ptr [ebx+8]
	add       esi,-12
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @27
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @29
	push      esi
	call      @InterlockedDecrement
	mov       eax,dword ptr [esi]
	inc       eax
	jmp       short @28
@29:
	mov       eax,1
	jmp       short @28
@27:
	mov       eax,1
@28:
	test      eax,eax
	jne       short @24
@26:
	mov       edx,dword ptr [ebx+8]
	add       edx,-12
	mov       dword ptr [ebp-40],edx
	mov       edi,dword ptr [ebx+8]
	add       edi,-12
	push      edi
	call      @$bdele$qpv
	pop       ecx
	xor       eax,eax
	mov       dword ptr [ebp-44],eax
	mov       edx,dword ptr [ebp-44]
	mov       dword ptr [ebx+8],edx
	mov       dword ptr [ebp-48],ebx
	mov       ecx,dword ptr [ebp-48]
	mov       eax,dword ptr [ecx+8]
	mov       dword ptr [ebp-68],eax
@24:
@25:
@23:
	dec       dword ptr [ebp-8]
	mov       ebx,dword ptr [ebp+8]
	add       ebx,116
	cmp       dword ptr [ebx+8],0
	je        short @32
	mov       eax,dword ptr [ebx+8]
	mov       edx,dword ptr [eax-12]
	inc       edx
	test      edx,edx
	je        short @35
	mov       esi,dword ptr [ebx+8]
	add       esi,-12
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @36
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @38
	push      esi
	call      @InterlockedDecrement
	mov       eax,dword ptr [esi]
	inc       eax
	jmp       short @37
@38:
	mov       eax,1
	jmp       short @37
@36:
	mov       eax,1
@37:
	test      eax,eax
	jne       short @33
@35:
	mov       edx,dword ptr [ebx+8]
	add       edx,-12
	mov       dword ptr [ebp-52],edx
	mov       edi,dword ptr [ebx+8]
	add       edi,-12
	push      edi
	call      @$bdele$qpv
	pop       ecx
	xor       eax,eax
	mov       dword ptr [ebp-56],eax
	mov       edx,dword ptr [ebp-56]
	mov       dword ptr [ebx+8],edx
	mov       dword ptr [ebp-60],ebx
	mov       ecx,dword ptr [ebp-60]
	mov       eax,dword ptr [ecx+8]
	mov       dword ptr [ebp-84],eax
@33:
@34:
@32:
	sub       dword ptr [ebp-8],6
	push      2
	mov       edx,dword ptr [ebp+8]
	add       edx,4
	push      edx
	call      @@CpuStats@$bdtr$qv
	add       esp,8
	test      byte ptr [ebp+12],1
	je        short @40
	mov       ecx,dword ptr [ebp+8]
	push      ecx
	call      @$bdele$qpv
	pop       ecx
@40:
@21:
	mov       eax,dword ptr [ebp-36]
	mov       dword ptr fs:[0],eax
@41:
	pop       edi
	pop       esi
	pop       ebx
	mov       esp,ebp
	pop       ebp
	ret 
@@CpuInfo@$bdtr$qv	endp
@CpuInfo@$bdtr$qv	ends
_TEXT	ends
_DATA	segment dword public use32 'DATA'
@_$DCXJB$@CpuInfo@determineCpuInfo$qv	segment virtual
	align	2
@@_$DCXJB$@CpuInfo@determineCpuInfo$qv	label	dword
	dd	@@$xt$67std@%basic_ostringstream$c19std@%char_traits$c%17std@%allocator$c%%
	dd	4
	dd	-176
	dd	0
	dd	@@$xt$67std@%basic_ostringstream$c19std@%char_traits$c%17std@%allocator$c%%
	dd	4
	dd	-176
	dd	0
	dd	@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	4
	dd	-192
	dd	0
@_$DCXJB$@CpuInfo@determineCpuInfo$qv	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@_$ECTYJB$@CpuInfo@determineCpuInfo$qv	segment virtual
	align	2
@@_$ECTYJB$@CpuInfo@determineCpuInfo$qv	label	dword
	dd	0
	dd	-228
	dw	0
	dw	5
	dd	0
	dd	@@_$DCXJB$@CpuInfo@determineCpuInfo$qv+16
	dw	0
	dw	5
	dd	0
	dd	@@_$DCXJB$@CpuInfo@determineCpuInfo$qv
	dw	20
	dw	5
	dd	10
	dd	@@_$DCXJB$@CpuInfo@determineCpuInfo$qv+32
	dw	20
	dw	5
	dd	0
	dd	0
@_$ECTYJB$@CpuInfo@determineCpuInfo$qv	ends
_DATA	ends
_TEXT	segment dword public use32 'CODE'
@CpuInfo@determineCpuInfo$qv	segment virtual
	align	2
@@CpuInfo@determineCpuInfo$qv	proc	near
?live16396@0:
@42:
	push      ebp
	mov       ebp,esp
	add       esp,-292
	mov       eax,offset @@_$ECTYJB$@CpuInfo@determineCpuInfo$qv
	push      ebx
	push      esi
	push      edi
	mov       ebx,dword ptr [ebp+8]
	call      @__InitExceptBlockLDTC
?live16396@16: ; EBX = this
	lea       edx,dword ptr [ebp-276]
	push      edx
	call      @GetSystemInfo
	mov       word ptr [ebp-212],8
	push      8
	push      0
	lea       ecx,dword ptr [ebp-176]
	push      ecx
	call      @@std@%basic_ostringstream$c19std@%char_traits$c%17std@%allocator$c%%@$bctr$qi
	add       esp,12
	add       dword ptr [ebp-200],10
	mov       word ptr [ebp-212],20
	push      offset @@std@%ends$c19std@%char_traits$c%%$qr42std@%basic_ostream$c19std@%char_traits$c%%$r42std@%basic_ostream$c19std@%char_traits$c%%
	mov       eax,dword ptr [ebp-256]
	push      eax
	lea       edx,dword ptr [ebp-176]
	push      edx
	call      @@std@%basic_ostream$c19std@%char_traits$c%%@$blsh$qul
	add       esp,8
	push      eax
	call      @@std@%basic_ostream$c19std@%char_traits$c%%@$blsh$qpqr42std@%basic_ostream$c19std@%char_traits$c%%$r42std@%basic_ostream$c19std@%char_traits$c%%
	add       esp,8
	mov       word ptr [ebp-212],32
	lea       ecx,dword ptr [ebp-176]
	push      ecx
	lea       eax,dword ptr [ebp-192]
	push      eax
	call      @@std@%basic_ostringstream$c19std@%char_traits$c%17std@%allocator$c%%@str$xqv
	add       esp,8
	lea       edx,dword ptr [ebp-192]
	push      edx
	inc       dword ptr [ebp-200]
	lea       ecx,dword ptr [ebx+132]
	push      ecx
	call      @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$basg$qrx60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	add       esp,8
	dec       dword ptr [ebp-200]
	cmp       dword ptr [ebp-184],0
	je        @44
	mov       eax,dword ptr [ebp-184]
	mov       edx,dword ptr [eax-12]
	inc       edx
	test      edx,edx
	je        short @47
	mov       esi,dword ptr [ebp-184]
	add       esi,-12
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @48
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @50
	push      esi
	call      @InterlockedDecrement
	mov       eax,dword ptr [esi]
	inc       eax
	jmp       short @49
@50:
	mov       eax,1
	jmp       short @49
@48:
	mov       eax,1
@49:
	test      eax,eax
	jne       short @45
@47:
	mov       edx,dword ptr [ebp-184]
	add       edx,-12
	mov       dword ptr [ebp-232],edx
	mov       edi,dword ptr [ebp-184]
	add       edi,-12
	push      edi
	call      @$bdele$qpv
	pop       ecx
	xor       eax,eax
	mov       dword ptr [ebp-236],eax
	lea       ecx,dword ptr [ebp-192]
	mov       edx,dword ptr [ebp-236]
	mov       dword ptr [ebp-184],edx
	mov       dword ptr [ebp-240],ecx
	mov       eax,dword ptr [ebp-240]
	mov       edx,dword ptr [eax+8]
	mov       dword ptr [ebp-284],edx
@45:
@46:
@44:
	mov       word ptr [ebp-212],20
	mov       cx,word ptr [ebp-276]
	push      ecx
	push      ebx
	mov       eax,dword ptr [ebx]
	call      dword ptr [eax+56]
	add       esp,8
?live16396@96: ; 
	sub       dword ptr [ebp-200],10
	push      2
	lea       edx,dword ptr [ebp-176]
	push      edx
	call      @@std@%basic_ostringstream$c19std@%char_traits$c%17std@%allocator$c%%@$bdtr$qv
	add       esp,8
	mov       ecx,dword ptr [ebp-228]
	mov       dword ptr fs:[0],ecx
@52:
	pop       edi
	pop       esi
	pop       ebx
	mov       esp,ebp
	pop       ebp
	ret 
@@CpuInfo@determineCpuInfo$qv	endp
@CpuInfo@determineCpuInfo$qv	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@std@%ends$c19std@%char_traits$c%%$qr42std@%basic_ostream$c19std@%char_traits$c%%$r42std@%basic_ostream$c19std@%char_traits$c%%	segment virtual
	align	2
@@std@%ends$c19std@%char_traits$c%%$qr42std@%basic_ostream$c19std@%char_traits$c%%$r42std@%basic_ostream$c19std@%char_traits$c%%	proc	near
?live16401@0:
@53:
	push      ebp
	mov       ebp,esp
	push      ebx
	mov       ebx,dword ptr [ebp+8]
?live16401@16: ; EBX = os
	push      0
	push      ebx
	call      @@std@%basic_ostream$c19std@%char_traits$c%%@put$qc
	add       esp,8
	mov       eax,ebx
?live16401@48: ; 
@55:
@54:
	pop       ebx
	pop       ebp
	ret 
@@std@%ends$c19std@%char_traits$c%%$qr42std@%basic_ostream$c19std@%char_traits$c%%$r42std@%basic_ostream$c19std@%char_traits$c%%	endp
@std@%ends$c19std@%char_traits$c%%$qr42std@%basic_ostream$c19std@%char_traits$c%%$r42std@%basic_ostream$c19std@%char_traits$c%%	ends
_TEXT	ends
_DATA	segment dword public use32 'DATA'
@_$DCZJB$@CpuInfo@determineCpuSpeed$qv	segment virtual
	align	2
@@_$DCZJB$@CpuInfo@determineCpuSpeed$qv	label	dword
	dd	@@$xt$67std@%basic_ostringstream$c19std@%char_traits$c%17std@%allocator$c%%
	dd	4
	dd	-176
	dd	0
	dd	@@$xt$67std@%basic_ostringstream$c19std@%char_traits$c%17std@%allocator$c%%
	dd	4
	dd	-176
	dd	0
	dd	@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	4
	dd	-192
	dd	0
@_$DCZJB$@CpuInfo@determineCpuSpeed$qv	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@_$ECTAKB$@CpuInfo@determineCpuSpeed$qv	segment virtual
	align	2
@@_$ECTAKB$@CpuInfo@determineCpuSpeed$qv	label	dword
	dd	0
	dd	-228
	dw	0
	dw	5
	dd	0
	dd	@@_$DCZJB$@CpuInfo@determineCpuSpeed$qv+16
	dw	0
	dw	5
	dd	0
	dd	@@_$DCZJB$@CpuInfo@determineCpuSpeed$qv
	dw	20
	dw	5
	dd	10
	dd	@@_$DCZJB$@CpuInfo@determineCpuSpeed$qv+32
	dw	20
	dw	5
	dd	0
	dd	0
@_$ECTAKB$@CpuInfo@determineCpuSpeed$qv	ends
_DATA	ends
_TEXT	segment dword public use32 'CODE'
@CpuInfo@determineCpuSpeed$qv	segment virtual
	align	2
@@CpuInfo@determineCpuSpeed$qv	proc	near
?live16402@0:
@56:
	push      ebp
	mov       ebp,esp
	add       esp,-260
	mov       eax,offset @@_$ECTAKB$@CpuInfo@determineCpuSpeed$qv
	push      ebx
	push      esi
	push      edi
	mov       ebx,dword ptr [ebp+8]
	call      @__InitExceptBlockLDTC
?live16402@16: ; EBX = this, ESI = dwSpeed
	mov       dword ptr [ebp-232],-1
?live16402@32: ; EBX = this, ESI = dwSpeed, EDI = nNumTimes
	lea       eax,dword ptr [ebx+4]
?live16402@48: ; EBX = this
	xor       esi,esi
?live16402@64: ; EBX = this, ESI = dwSpeed, EDI = nNumTimes
	push      eax
?live16402@80: ; EBX = this, ESI = dwSpeed
	xor       edi,edi
?live16402@96: ; EBX = this, ESI = dwSpeed, EDI = nNumTimes
	mov       edx,dword ptr [ebx+4]
	call      dword ptr [edx+36]
	pop       ecx
	dec       eax
	jne       short @59
	lea       ecx,dword ptr [ebx+4]
	push      ecx
	mov       eax,dword ptr [ebx+4]
	call      dword ptr [eax+16]
	pop       ecx
	cmp       eax,4
	jg        short @58
@59:
	lea       edx,dword ptr [ebx+4]
	push      edx
	mov       ecx,dword ptr [ebx+4]
	call      dword ptr [ecx+36]
	pop       ecx
	cmp       eax,2
	jne       @57
	lea       eax,dword ptr [ebx+4]
	push      eax
	mov       edx,dword ptr [ebx+4]
	call      dword ptr [edx+16]
	pop       ecx
	cmp       eax,5
	jle       @57
@58:
@60:
	call      @GetCurrentProcess
	push      eax
	call      @GetPriorityClass
	mov       dword ptr [ebp-236],eax
	push      128
	call      @GetCurrentProcess
	push      eax
	call      @SetPriorityClass
	jmp       short @62
@61:
	mov       dword ptr [ebp-232],esi
?live16402@160: ; EBX = this, EDI = nNumTimes
	push      ebx
	mov       ecx,dword ptr [ebx]
	call      dword ptr [ecx+100]
	pop       ecx
	mov       esi,eax
?live16402@176: ; EBX = this, ESI = dwSpeed, EDI = nNumTimes
	inc       edi
@62:
	cmp       esi,dword ptr [ebp-232]
	je        short @63
	cmp       edi,10
	jl        short @61
@63:
	mov       eax,dword ptr [ebp-236]
	push      eax
	call      @GetCurrentProcess
	push      eax
	call      @SetPriorityClass
	cmp       edi,10
	je        @64
?live16402@240: ; EBX = this, ESI = dwSpeed
@65:
	mov       word ptr [ebp-212],8
	push      8
	push      0
	lea       edx,dword ptr [ebp-176]
	push      edx
	call      @@std@%basic_ostringstream$c19std@%char_traits$c%17std@%allocator$c%%@$bctr$qi
	add       esp,12
	add       dword ptr [ebp-200],10
	mov       word ptr [ebp-212],20
	push      offset @@std@%ends$c19std@%char_traits$c%%$qr42std@%basic_ostream$c19std@%char_traits$c%%$r42std@%basic_ostream$c19std@%char_traits$c%%
	push      offset s@+2
	push      esi
	lea       ecx,dword ptr [ebp-176]
	push      ecx
	call      @@std@%basic_ostream$c19std@%char_traits$c%%@$blsh$qul
	add       esp,8
	push      eax
	call      @@std@$blsh$qr42std@%basic_ostream$c19std@%char_traits$c%%pxc$r42std@%basic_ostream$c19std@%char_traits$c%%
	add       esp,8
	push      eax
	call      @@std@%basic_ostream$c19std@%char_traits$c%%@$blsh$qpqr42std@%basic_ostream$c19std@%char_traits$c%%$r42std@%basic_ostream$c19std@%char_traits$c%%
	add       esp,8
?live16402@272: ; EBX = this
	mov       word ptr [ebp-212],32
	lea       eax,dword ptr [ebp-176]
	push      eax
	lea       edx,dword ptr [ebp-192]
	push      edx
	call      @@std@%basic_ostringstream$c19std@%char_traits$c%17std@%allocator$c%%@str$xqv
	add       esp,8
	lea       ecx,dword ptr [ebp-192]
	push      ecx
	inc       dword ptr [ebp-200]
	add       ebx,116
	push      ebx
	call      @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$basg$qrx60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	add       esp,8
	dec       dword ptr [ebp-200]
	cmp       dword ptr [ebp-184],0
	je        @67
	mov       eax,dword ptr [ebp-184]
	mov       edx,dword ptr [eax-12]
	inc       edx
	test      edx,edx
	je        short @70
	mov       ebx,dword ptr [ebp-184]
	add       ebx,-12
	cmp       ebx,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @71
	cmp       ebx,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @73
	push      ebx
	call      @InterlockedDecrement
	mov       eax,dword ptr [ebx]
	inc       eax
	jmp       short @72
@73:
	mov       eax,1
	jmp       short @72
@71:
	mov       eax,1
@72:
	test      eax,eax
	jne       short @68
@70:
	mov       edx,dword ptr [ebp-184]
	add       edx,-12
	mov       dword ptr [ebp-240],edx
	mov       esi,dword ptr [ebp-184]
	add       esi,-12
	push      esi
	call      @$bdele$qpv
	xor       eax,eax
	pop       ecx
	mov       edi,eax
	lea       edx,dword ptr [ebp-192]
	mov       dword ptr [ebp-184],edi
	mov       dword ptr [ebp-244],edx
	mov       ecx,dword ptr [ebp-244]
	mov       eax,dword ptr [ecx+8]
	mov       dword ptr [ebp-252],eax
@68:
@69:
@67:
	mov       word ptr [ebp-212],20
?live16402@288: ; 
	sub       dword ptr [ebp-200],10
	push      2
	lea       edx,dword ptr [ebp-176]
	push      edx
	call      @@std@%basic_ostringstream$c19std@%char_traits$c%17std@%allocator$c%%@$bdtr$qv
	mov       word ptr [ebp-212],0
	add       esp,8
@75:
@64:
@76:
@57:
	mov       ecx,dword ptr [ebp-228]
	mov       dword ptr fs:[0],ecx
@77:
	pop       edi
	pop       esi
	pop       ebx
	mov       esp,ebp
	pop       ebp
	ret 
@@CpuInfo@determineCpuSpeed$qv	endp
@CpuInfo@determineCpuSpeed$qv	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@CpuInfo@assign$qrx7CpuInfo	segment virtual
	align	2
@@CpuInfo@assign$qrx7CpuInfo	proc	near
?live16405@0:
@78:
	push      ebp
	mov       ebp,esp
	push      ebx
	push      esi
	mov       esi,dword ptr [ebp+12]
	mov       ebx,dword ptr [ebp+8]
?live16405@16: ; EBX = this, ESI = source
	lea       eax,dword ptr [esi+4]
	push      eax
	lea       edx,dword ptr [ebx+4]
	push      edx
	call      @@CpuStats@$basg$qrx8CpuStats
	add       esp,8
	lea       ecx,dword ptr [esi+116]
	push      ecx
	lea       eax,dword ptr [ebx+116]
	push      eax
	call      @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$basg$qrx60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	add       esp,8
	add       esi,132
	push      esi
	add       ebx,132
	push      ebx
	call      @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$basg$qrx60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	add       esp,8
?live16405@64: ; 
@79:
	pop       esi
	pop       ebx
	pop       ebp
	ret 
@@CpuInfo@assign$qrx7CpuInfo	endp
@CpuInfo@assign$qrx7CpuInfo	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@CpuInfo@determineCpuStats$qus	segment virtual
	align	2
@@CpuInfo@determineCpuStats$qus	proc	near
?live16406@0:
@80:
	push      ebp
	mov       ebp,esp
	push      ecx
	push      ebx
	mov       ebx,dword ptr [ebp+8]
?live16406@16: ; EBX = this
	push      ebx
	mov       eax,dword ptr [ebx]
	call      dword ptr [eax+52]
	pop       ecx
	test      al,al
	je        @82
	mov       byte ptr [ebp-1],1
	lea       edx,dword ptr [ebp-1]
	lea       ecx,dword ptr [ebx+4]
	push      edx
	push      ecx
	mov       eax,dword ptr [ebx+4]
	call      dword ptr [eax+4]
	add       esp,8
	push      ebx
	mov       edx,dword ptr [ebx]
	call      dword ptr [edx+60]
	pop       ecx
?live16406@64: ; EBX = this, EAX = dwHighestCpuId
	sub       eax,1
	jb        short @82
	je        short @86
	dec       eax
	jne       short @82
?live16406@80: ; EBX = this
	push      ebx
	mov       ecx,dword ptr [ebx]
	call      dword ptr [ecx+68]
	pop       ecx
@86:
	push      ebx
	mov       eax,dword ptr [ebx]
	call      dword ptr [eax+64]
	pop       ecx
	lea       edx,dword ptr [ebx+4]
	push      edx
	mov       ecx,dword ptr [ebx+4]
	call      dword ptr [ecx+36]
	pop       ecx
	dec       eax
	jne       short @89
	push      ebx
	mov       eax,dword ptr [ebx]
	call      dword ptr [eax+72]
	pop       ecx
@89:
	push      ebx
	mov       edx,dword ptr [ebx]
	call      dword ptr [edx+80]
	pop       ecx
?live16406@160: ; EBX = this, EAX = dwLargestExtendedFeature
	cmp       eax,-2147483643
	jg        short @96
	je        short @93
	sub       eax,-2147483647
	je        short @95
	sub       eax,3
	je        short @94
	jmp       short @97
@96:
	sub       eax,-2147483642
	je        short @92
	sub       eax,2147483642
	je        short @97
	jmp       short @97
?live16406@176: ; EBX = this
@92:
	push      ebx
	mov       ecx,dword ptr [ebx]
	call      dword ptr [ecx+96]
	pop       ecx
@93:
	push      ebx
	mov       eax,dword ptr [ebx]
	call      dword ptr [eax+92]
	pop       ecx
@94:
	push      ebx
	mov       edx,dword ptr [ebx]
	call      dword ptr [edx+88]
	pop       ecx
@95:
	push      ebx
	mov       ecx,dword ptr [ebx]
	call      dword ptr [ecx+84]
	pop       ecx
?live16406@240: ; 
@97:
@98:
@82:
	pop       ebx
	pop       ecx
	pop       ebp
	ret 
@@CpuInfo@determineCpuStats$qus	endp
@CpuInfo@determineCpuStats$qus	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@CpuInfo@determineCpuId$qv	segment virtual
	align	2
@@CpuInfo@determineCpuId$qv	proc	near
?live16407@0:
	push      ebp
	mov       ebp,esp
	push      ecx
@99:
	xor       eax,eax
	mov       dword ptr [ebp-4],eax
	pushfd	                      
	pop	     eax                 
	mov	     edx, eax            
	xor	     eax, 0200000h       
	push	    eax                 
	popfd	                       
	pushfd	
	pop	     eax
	xor	     eax, edx            
	jne       short @100
	mov	     dword ptr [ebp-4], 0      
	jmp       @101
@100:
has_cpuid:
	mov	     dword ptr [ebp-4], 1      
@101:
done:
	cmp       dword ptr [ebp-4],0
	setne     al
	and       eax,1
@103:
@102:
	pop       ecx
	pop       ebp
	ret 
@@CpuInfo@determineCpuId$qv	endp
@CpuInfo@determineCpuId$qv	ends
_TEXT	ends
_DATA	segment dword public use32 'DATA'
$iepkfgia	label	byte
	db	0
	db	15	dup(?)
_DATA	ends
_DATA	segment dword public use32 'DATA'
@_$DCBKB$@CpuInfo@determineHighestCpuId$qv	segment virtual
	align	2
@@_$DCBKB$@CpuInfo@determineHighestCpuId$qv	label	dword
	dd	@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	4
	dd	-16
	dd	0
	dd	@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	4
	dd	-16
	dd	0
@_$DCBKB$@CpuInfo@determineHighestCpuId$qv	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@_$ECTCKB$@CpuInfo@determineHighestCpuId$qv	segment virtual
	align	2
@@_$ECTCKB$@CpuInfo@determineHighestCpuId$qv	label	dword
	dd	0
	dd	-52
	dw	0
	dw	5
	dd	0
	dd	@@_$DCBKB$@CpuInfo@determineHighestCpuId$qv
	dw	8
	dw	5
	dd	0
	dd	@@_$DCBKB$@CpuInfo@determineHighestCpuId$qv+16
	dw	8
	dw	5
	dd	0
	dd	0
@_$ECTCKB$@CpuInfo@determineHighestCpuId$qv	ends
_DATA	ends
_TEXT	segment dword public use32 'CODE'
@CpuInfo@determineHighestCpuId$qv	segment virtual
	align	2
@@CpuInfo@determineHighestCpuId$qv	proc	near
?live16408@0:
	push      ebp
	mov       ebp,esp
	add       esp,-104
	push      ebx
	push      esi
	push      edi
	mov       esi,dword ptr [ebp+8]
@104:
	mov       eax,offset @@_$ECTCKB$@CpuInfo@determineHighestCpuId$qv
	call      @__InitExceptBlockLDTC
?live16408@16: ; ESI = this
	xor       edx,edx
	lea       edi,dword ptr [ebp-88]
	mov       dword ptr [ebp-56],edx
	push      esi
	mov       esi,offset $iepkfgia
	mov       ecx,4
	rep   movsd
	pop       esi
?live16408@80: ; 
	mov	      eax, 0
	CPUID	
	test	    eax,eax                   
?live16408@128: ; ESI = this
	je        short @105
?live16408@144: ; 
	mov	     dword ptr [ebp-56], eax            
	mov	     DWORD PTR [byte ptr [ebp-88]+0],ebx  
	mov	     DWORD PTR [byte ptr [ebp-88]+4],edx
	mov	     DWORD PTR [byte ptr [ebp-88]+8],ecx
@105:
no_features:
?live16408@224: ; ESI = this
	cmp       dword ptr [ebp-56],0
	je        @106
@107:
	mov       word ptr [ebp-36],20
	lea       eax,dword ptr [ebp-64]
	push      eax
	lea       edx,dword ptr [ebp-88]
	push      edx
	lea       ecx,dword ptr [ebp-16]
	push      ecx
	call      @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$bctr$qpxcrx17std@%allocator$c%
	add       esp,12
	lea       eax,dword ptr [ebp-16]
	inc       dword ptr [ebp-24]
	lea       edx,dword ptr [esi+4]
	mov       word ptr [ebp-36],8
	push      eax
	push      edx
	mov       ecx,dword ptr [esi+4]
	call      dword ptr [ecx+104]
	add       esp,8
?live16408@336: ; 
	dec       dword ptr [ebp-24]
	cmp       dword ptr [ebp-8],0
	je        short @109
@108:
	mov       eax,dword ptr [ebp-8]
	mov       edx,dword ptr [eax-12]
	inc       edx
	test      edx,edx
	je        short @112
	mov       ebx,dword ptr [ebp-8]
	add       ebx,-12
	cmp       ebx,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @113
	cmp       ebx,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @115
	push      ebx
	call      @InterlockedDecrement
	mov       eax,dword ptr [ebx]
	inc       eax
	jmp       short @114
@115:
	mov       eax,1
@116:
	jmp       short @114
@113:
	mov       eax,1
@114:
	test      eax,eax
	jne       short @110
@112:
	mov       edx,dword ptr [ebp-8]
	add       edx,-12
	mov       dword ptr [ebp-68],edx
	mov       esi,dword ptr [ebp-8]
	add       esi,-12
	push      esi
	call      @$bdele$qpv
	xor       eax,eax
	pop       ecx
	mov       edi,eax
	lea       edx,dword ptr [ebp-16]
	mov       dword ptr [ebp-8],edi
	mov       dword ptr [ebp-72],edx
	mov       ecx,dword ptr [ebp-72]
	mov       eax,dword ptr [ecx+8]
	mov       dword ptr [ebp-96],eax
@110:
@111:
@109:
	mov       word ptr [ebp-36],0
@117:
@106:
	mov       eax,dword ptr [ebp-56]
	mov       edx,dword ptr [ebp-52]
	mov       dword ptr fs:[0],edx
@119:
@118:
	pop       edi
	pop       esi
	pop       ebx
	mov       esp,ebp
	pop       ebp
	ret 
@@CpuInfo@determineHighestCpuId$qv	endp
@CpuInfo@determineHighestCpuId$qv	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@CpuInfo@determineCpuIdentification$qv	segment virtual
	align	2
@@CpuInfo@determineCpuIdentification$qv	proc	near
?live16411@0:
	push      ebp
	mov       ebp,esp
	add       esp,-16
	push      ebx
	push      esi
	mov       esi,dword ptr [ebp+8]
?live16411@16: ; ESI = this
@120:
	xor       eax,eax
	mov       dword ptr [ebp-4],eax
	xor       edx,edx
	mov       dword ptr [ebp-8],edx
	xor       ecx,ecx
	mov       dword ptr [ebp-12],ecx
	xor       eax,eax
	mov       dword ptr [ebp-16],eax
?live16411@80: ; 
	mov	      eax, 1
	CPUID	
	mov	      [dword ptr [ebp-4]], eax     
	mov	      [dword ptr [ebp-8]], ebx    
	mov	      [dword ptr [ebp-12]], ecx
	mov	      [dword ptr [ebp-16]], edx      
?live16411@176: ; ESI = this
	lea       edx,dword ptr [ebp-4]
	lea       ebx,dword ptr [esi+4]
	push      edx
	push      ebx
	mov       eax,dword ptr [esi+4]
	call      dword ptr [eax+96]
	add       esp,8
?live16411@192: ; ESI = this, EBX = @temp1
	lea       edx,dword ptr [ebp-8]
	push      edx
	push      ebx
	mov       ecx,dword ptr [esi+4]
	call      dword ptr [ecx+116]
	add       esp,8
	lea       eax,dword ptr [ebp-12]
	push      eax
	push      ebx
	mov       edx,dword ptr [esi+4]
	call      dword ptr [edx+120]
	add       esp,8
	lea       ecx,dword ptr [ebp-16]
	push      ecx
	push      ebx
	mov       eax,dword ptr [esi+4]
	call      dword ptr [eax+108]
	add       esp,8
?live16411@240: ; 
@121:
	pop       esi
	pop       ebx
	mov       esp,ebp
	pop       ebp
	ret 
@@CpuInfo@determineCpuIdentification$qv	endp
@CpuInfo@determineCpuIdentification$qv	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@CpuInfo@determineLargestExtendedFeature$qv	segment virtual
	align	2
@@CpuInfo@determineLargestExtendedFeature$qv	proc	near
?live16412@0:
	push      ebp
	mov       ebp,esp
	push      ecx
@122:
	xor       eax,eax
	mov       dword ptr [ebp-4],eax
	mov	      eax, 080000000H
	CPUID	
	mov	 dword ptr [ebp-4], eax
	mov       eax,dword ptr [ebp-4]
@124:
@123:
	pop       ecx
	pop       ebp
	ret 
@@CpuInfo@determineLargestExtendedFeature$qv	endp
@CpuInfo@determineLargestExtendedFeature$qv	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@CpuInfo@determineExtendedFeature$qv	segment virtual
	align	2
@@CpuInfo@determineExtendedFeature$qv	proc	near
?live16413@0:
	push      ebp
	mov       ebp,esp
	push      ecx
	mov       ecx,dword ptr [ebp+8]
?live16413@16: ; ECX = this
@125:
	xor       eax,eax
	mov       dword ptr [ebp-4],eax
?live16413@32: ; 
	mov	      eax, 080000001H
	CPUID	
	mov	 dword ptr [ebp-4], edx
?live16413@80: ; ECX = this
	lea       edx,dword ptr [ebp-4]
	lea       eax,dword ptr [ecx+4]
	push      edx
	push      eax
	mov       edx,dword ptr [ecx+4]
	call      dword ptr [edx+112]
	add       esp,8
?live16413@96: ; 
@126:
	pop       ecx
	pop       ebp
	ret 
@@CpuInfo@determineExtendedFeature$qv	endp
@CpuInfo@determineExtendedFeature$qv	ends
_TEXT	ends
_DATA	segment dword public use32 'DATA'
$aipkfgia	label	byte
	db	0
	db	63	dup(?)
_DATA	ends
_DATA	segment dword public use32 'DATA'
@_$DCDKB$@CpuInfo@determineNameString$qv	segment virtual
	align	2
@@_$DCDKB$@CpuInfo@determineNameString$qv	label	dword
	dd	@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	4
	dd	-16
	dd	0
@_$DCDKB$@CpuInfo@determineNameString$qv	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@_$ECTEKB$@CpuInfo@determineNameString$qv	segment virtual
	align	2
@@_$ECTEKB$@CpuInfo@determineNameString$qv	label	dword
	dd	0
	dd	-52
	dw	0
	dw	5
	dd	0
	dd	@@_$DCDKB$@CpuInfo@determineNameString$qv
	dw	0
	dw	5
	dd	0
	dd	0
@_$ECTEKB$@CpuInfo@determineNameString$qv	ends
_DATA	ends
_TEXT	segment dword public use32 'CODE'
@CpuInfo@determineNameString$qv	segment virtual
	align	2
@@CpuInfo@determineNameString$qv	proc	near
?live16414@0:
	push      ebp
	mov       ebp,esp
	add       esp,-148
	push      ebx
	push      esi
	push      edi
	mov       esi,dword ptr [ebp+8]
@127:
	mov       eax,offset @@_$ECTEKB$@CpuInfo@determineNameString$qv
	call      @__InitExceptBlockLDTC
?live16414@16: ; ESI = this
	push      esi
	mov       esi,offset $aipkfgia
	lea       edi,dword ptr [ebp-132]
	mov       ecx,16
	rep   movsd
	pop       esi
?live16414@32: ; 
	mov	      eax, 080000002H
	CPUID	
	mov	      DWORD PTR [byte ptr [ebp-132]+0],eax
	mov	      DWORD PTR [byte ptr [ebp-132]+4],ebx
	mov	      DWORD PTR [byte ptr [ebp-132]+8],ecx
	mov	      DWORD PTR [byte ptr [ebp-132]+12],edx
	mov	      eax, 080000003H
	CPUID	
	mov	      DWORD PTR [byte ptr [ebp-132]+16],eax
	mov	      DWORD PTR [byte ptr [ebp-132]+20],ebx
	mov	      DWORD PTR [byte ptr [ebp-132]+24],ecx
	mov	      DWORD PTR [byte ptr [ebp-132]+28],edx
	mov	      eax, 080000004H
	CPUID	
	mov	      DWORD PTR [byte ptr [ebp-132]+32],eax
	mov	      DWORD PTR [byte ptr [ebp-132]+36],ebx
	mov	      DWORD PTR [byte ptr [ebp-132]+40],ecx
	mov	      DWORD PTR [byte ptr [ebp-132]+44],edx
?live16414@320: ; ESI = this
	mov       word ptr [ebp-36],8
	lea       eax,dword ptr [ebp-60]
	push      eax
	lea       edx,dword ptr [ebp-132]
	push      edx
	lea       ecx,dword ptr [ebp-16]
	push      ecx
	call      @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$bctr$qpxcrx17std@%allocator$c%
	add       esp,12
	lea       eax,dword ptr [ebp-16]
	inc       dword ptr [ebp-24]
	lea       edx,dword ptr [esi+4]
	push      eax
	push      edx
	mov       ecx,dword ptr [esi+4]
	call      dword ptr [ecx+100]
	add       esp,8
	dec       dword ptr [ebp-24]
	cmp       dword ptr [ebp-8],0
	je        short @129
@128:
	mov       eax,dword ptr [ebp-8]
	mov       edx,dword ptr [eax-12]
	inc       edx
	test      edx,edx
	je        short @132
	mov       ebx,dword ptr [ebp-8]
	add       ebx,-12
	cmp       ebx,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @133
	cmp       ebx,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @135
	push      ebx
	call      @InterlockedDecrement
	mov       eax,dword ptr [ebx]
	inc       eax
	jmp       short @134
@135:
	mov       eax,1
@136:
	jmp       short @134
@133:
	mov       eax,1
@134:
	test      eax,eax
	jne       short @130
@132:
	mov       edx,dword ptr [ebp-8]
	add       edx,-12
	mov       dword ptr [ebp-64],edx
	mov       esi,dword ptr [ebp-8]
	add       esi,-12
	push      esi
	call      @$bdele$qpv
	xor       eax,eax
	pop       ecx
	mov       edi,eax
	lea       edx,dword ptr [ebp-16]
	mov       dword ptr [ebp-8],edi
	mov       dword ptr [ebp-68],edx
	mov       ecx,dword ptr [ebp-68]
	mov       eax,dword ptr [ecx+8]
	mov       dword ptr [ebp-140],eax
?live16414@336: ; 
@130:
@131:
@129:
	mov       edx,dword ptr [ebp-52]
	mov       dword ptr fs:[0],edx
@137:
	pop       edi
	pop       esi
	pop       ebx
	mov       esp,ebp
	pop       ebp
	ret 
@@CpuInfo@determineNameString$qv	endp
@CpuInfo@determineNameString$qv	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@CpuInfo@determineAmdL1CacheInfo$qv	segment virtual
	align	2
@@CpuInfo@determineAmdL1CacheInfo$qv	proc	near
?live16417@0:
	push      ebp
	mov       ebp,esp
	add       esp,-16
	push      ebx
	push      esi
	mov       esi,dword ptr [ebp+8]
?live16417@16: ; ESI = this
@138:
	xor       eax,eax
	mov       dword ptr [ebp-4],eax
	xor       edx,edx
	mov       dword ptr [ebp-8],edx
	xor       ecx,ecx
	mov       dword ptr [ebp-12],ecx
	xor       eax,eax
	mov       dword ptr [ebp-16],eax
?live16417@80: ; 
	mov	      eax, 080000005H
	CPUID	
	mov	      dword ptr [ebp-4], eax
	mov	      dword ptr [ebp-8], ebx
	mov	      dword ptr [ebp-12], ecx
	mov	      dword ptr [ebp-16], edx
?live16417@176: ; ESI = this
	lea       edx,dword ptr [ebp-4]
	lea       ebx,dword ptr [esi+4]
	push      edx
	push      ebx
	mov       eax,dword ptr [esi+4]
	call      dword ptr [eax+124]
	add       esp,8
?live16417@192: ; ESI = this, EBX = @temp1
	lea       edx,dword ptr [ebp-8]
	push      edx
	push      ebx
	mov       ecx,dword ptr [esi+4]
	call      dword ptr [ecx+128]
	add       esp,8
	lea       eax,dword ptr [ebp-12]
	push      eax
	push      ebx
	mov       edx,dword ptr [esi+4]
	call      dword ptr [edx+132]
	add       esp,8
	lea       ecx,dword ptr [ebp-16]
	push      ecx
	push      ebx
	mov       eax,dword ptr [esi+4]
	call      dword ptr [eax+136]
	add       esp,8
?live16417@240: ; 
@139:
	pop       esi
	pop       ebx
	mov       esp,ebp
	pop       ebp
	ret 
@@CpuInfo@determineAmdL1CacheInfo$qv	endp
@CpuInfo@determineAmdL1CacheInfo$qv	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@CpuInfo@determineAmdL2CacheInfo$qv	segment virtual
	align	2
@@CpuInfo@determineAmdL2CacheInfo$qv	proc	near
?live16418@0:
	push      ebp
	mov       ebp,esp
	add       esp,-16
	push      ebx
	push      esi
	mov       esi,dword ptr [ebp+8]
?live16418@16: ; ESI = this
@140:
	xor       eax,eax
	mov       dword ptr [ebp-4],eax
	xor       edx,edx
	mov       dword ptr [ebp-8],edx
	xor       ecx,ecx
	mov       dword ptr [ebp-12],ecx
	xor       eax,eax
	mov       dword ptr [ebp-16],eax
?live16418@80: ; 
	mov	      eax, 080000006H
	CPUID	
	mov	      dword ptr [ebp-4], eax
	mov	      dword ptr [ebp-8], ebx
	mov	      dword ptr [ebp-12], ecx
	mov	      dword ptr [ebp-16], edx
?live16418@176: ; ESI = this
	lea       edx,dword ptr [ebp-4]
	lea       ebx,dword ptr [esi+4]
	push      edx
	push      ebx
	mov       eax,dword ptr [esi+4]
	call      dword ptr [eax+140]
	add       esp,8
?live16418@192: ; ESI = this, EBX = @temp1
	lea       edx,dword ptr [ebp-8]
	push      edx
	push      ebx
	mov       ecx,dword ptr [esi+4]
	call      dword ptr [ecx+144]
	add       esp,8
	lea       eax,dword ptr [ebp-12]
	push      eax
	push      ebx
	mov       edx,dword ptr [esi+4]
	call      dword ptr [edx+148]
	add       esp,8
	lea       ecx,dword ptr [ebp-16]
	push      ecx
	push      ebx
	mov       eax,dword ptr [esi+4]
	call      dword ptr [eax+152]
	add       esp,8
?live16418@240: ; 
@141:
	pop       esi
	pop       ebx
	mov       esp,ebp
	pop       ebp
	ret 
@@CpuInfo@determineAmdL2CacheInfo$qv	endp
@CpuInfo@determineAmdL2CacheInfo$qv	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@CpuInfo@determineIntelCacheInfo$qv	segment virtual
	align	2
@@CpuInfo@determineIntelCacheInfo$qv	proc	near
?live16419@0:
	push      ebp
	mov       ebp,esp
	add       esp,-16
	push      ebx
	push      esi
	mov       esi,dword ptr [ebp+8]
?live16419@16: ; ESI = this
@142:
	xor       eax,eax
	mov       dword ptr [ebp-4],eax
	xor       edx,edx
	mov       dword ptr [ebp-8],edx
	xor       ecx,ecx
	mov       dword ptr [ebp-12],ecx
	xor       eax,eax
	mov       dword ptr [ebp-16],eax
?live16419@80: ; 
	mov	      eax, 2
	CPUID	
	cmp	      al, 1
?live16419@128: ; ESI = this
	jne       short @143
?live16419@144: ; 
	mov	      dword ptr [ebp-4], eax
	mov	      dword ptr [ebp-8], ebx
	mov	      dword ptr [ebp-12], ecx
	mov	      dword ptr [ebp-16], edx
@143:
end_find_intel_cacheinfo:
?live16419@224: ; ESI = this
	lea       edx,dword ptr [ebp-4]
	lea       ebx,dword ptr [esi+4]
	push      edx
	push      ebx
	mov       eax,dword ptr [esi+4]
	call      dword ptr [eax+124]
	add       esp,8
?live16419@240: ; ESI = this, EBX = @temp1
	lea       edx,dword ptr [ebp-8]
	push      edx
	push      ebx
	mov       ecx,dword ptr [esi+4]
	call      dword ptr [ecx+128]
	add       esp,8
	lea       eax,dword ptr [ebp-12]
	push      eax
	push      ebx
	mov       edx,dword ptr [esi+4]
	call      dword ptr [edx+132]
	add       esp,8
	lea       ecx,dword ptr [ebp-16]
	push      ecx
	push      ebx
	mov       eax,dword ptr [esi+4]
	call      dword ptr [eax+136]
	add       esp,8
?live16419@288: ; 
@144:
	pop       esi
	pop       ebx
	mov       esp,ebp
	pop       ebp
	ret 
@@CpuInfo@determineIntelCacheInfo$qv	endp
@CpuInfo@determineIntelCacheInfo$qv	ends
_TEXT	ends
_DATA	segment dword public use32 'DATA'
	align	4
$akalfgia	label	byte
	dd	1
	dd	s@+7
	dd	2
	dd	s@+43
	dd	3
	dd	s@+82
	dd	8
	dd	s@+130
_DATA	ends
_DATA	segment dword public use32 'DATA'
@_$DCFKB$@CpuInfo@determineOldIntelName$qv	segment virtual
	align	2
@@_$DCFKB$@CpuInfo@determineOldIntelName$qv	label	dword
	dd	@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	4
	dd	-16
	dd	0
	dd	@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	4
	dd	-32
	dd	0
	dd	@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	4
	dd	-48
	dd	0
	dd	@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	4
	dd	-64
	dd	0
	dd	@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	4
	dd	-80
	dd	0
	dd	@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	4
	dd	-96
	dd	0
	dd	@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	4
	dd	-112
	dd	0
	dd	@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	4
	dd	-128
	dd	0
	dd	@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	4
	dd	-144
	dd	0
	dd	@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	4
	dd	-160
	dd	0
	dd	@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	4
	dd	-176
	dd	0
	dd	@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	4
	dd	-192
	dd	0
	dd	@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	4
	dd	-208
	dd	0
	dd	@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	4
	dd	-224
	dd	0
	dd	@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	4
	dd	-240
	dd	0
	dd	@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	4
	dd	-256
	dd	0
	dd	@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	4
	dd	-272
	dd	0
	dd	@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	4
	dd	-288
	dd	0
	dd	@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	4
	dd	-304
	dd	0
	dd	@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	4
	dd	-320
	dd	0
	dd	@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	4
	dd	-336
	dd	0
	dd	@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	4
	dd	-336
	dd	0
@_$DCFKB$@CpuInfo@determineOldIntelName$qv	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@_$ECTGKB$@CpuInfo@determineOldIntelName$qv	segment virtual
	align	2
@@_$ECTGKB$@CpuInfo@determineOldIntelName$qv	label	dword
	dd	0
	dd	-372
	dw	0
	dw	5
	dd	0
	dd	@@_$DCFKB$@CpuInfo@determineOldIntelName$qv
	dw	0
	dw	5
	dd	0
	dd	0
	dw	0
	dw	5
	dd	0
	dd	@@_$DCFKB$@CpuInfo@determineOldIntelName$qv+16
	dw	0
	dw	5
	dd	0
	dd	0
	dw	0
	dw	5
	dd	0
	dd	@@_$DCFKB$@CpuInfo@determineOldIntelName$qv+32
	dw	0
	dw	5
	dd	0
	dd	0
	dw	0
	dw	5
	dd	0
	dd	@@_$DCFKB$@CpuInfo@determineOldIntelName$qv+48
	dw	0
	dw	5
	dd	0
	dd	0
	dw	0
	dw	5
	dd	0
	dd	@@_$DCFKB$@CpuInfo@determineOldIntelName$qv+64
	dw	0
	dw	5
	dd	0
	dd	0
	dw	0
	dw	5
	dd	0
	dd	@@_$DCFKB$@CpuInfo@determineOldIntelName$qv+80
	dw	0
	dw	5
	dd	0
	dd	0
	dw	0
	dw	5
	dd	0
	dd	@@_$DCFKB$@CpuInfo@determineOldIntelName$qv+96
	dw	0
	dw	5
	dd	0
	dd	0
	dw	0
	dw	5
	dd	0
	dd	@@_$DCFKB$@CpuInfo@determineOldIntelName$qv+112
	dw	0
	dw	5
	dd	0
	dd	0
	dw	0
	dw	5
	dd	0
	dd	@@_$DCFKB$@CpuInfo@determineOldIntelName$qv+128
	dw	0
	dw	5
	dd	0
	dd	0
	dw	0
	dw	5
	dd	0
	dd	@@_$DCFKB$@CpuInfo@determineOldIntelName$qv+144
	dw	0
	dw	5
	dd	0
	dd	0
	dw	0
	dw	5
	dd	0
	dd	@@_$DCFKB$@CpuInfo@determineOldIntelName$qv+160
	dw	0
	dw	5
	dd	0
	dd	0
	dw	0
	dw	5
	dd	0
	dd	@@_$DCFKB$@CpuInfo@determineOldIntelName$qv+176
	dw	0
	dw	5
	dd	0
	dd	0
	dw	0
	dw	5
	dd	0
	dd	@@_$DCFKB$@CpuInfo@determineOldIntelName$qv+192
	dw	0
	dw	5
	dd	0
	dd	0
	dw	0
	dw	5
	dd	0
	dd	@@_$DCFKB$@CpuInfo@determineOldIntelName$qv+208
	dw	0
	dw	5
	dd	0
	dd	0
	dw	0
	dw	5
	dd	0
	dd	@@_$DCFKB$@CpuInfo@determineOldIntelName$qv+224
	dw	0
	dw	5
	dd	0
	dd	0
	dw	0
	dw	5
	dd	0
	dd	@@_$DCFKB$@CpuInfo@determineOldIntelName$qv+240
	dw	0
	dw	5
	dd	0
	dd	0
	dw	0
	dw	5
	dd	0
	dd	@@_$DCFKB$@CpuInfo@determineOldIntelName$qv+256
	dw	0
	dw	5
	dd	0
	dd	0
	dw	0
	dw	5
	dd	0
	dd	@@_$DCFKB$@CpuInfo@determineOldIntelName$qv+272
	dw	0
	dw	5
	dd	0
	dd	0
	dw	0
	dw	5
	dd	0
	dd	@@_$DCFKB$@CpuInfo@determineOldIntelName$qv+288
	dw	0
	dw	5
	dd	0
	dd	0
	dw	0
	dw	5
	dd	0
	dd	@@_$DCFKB$@CpuInfo@determineOldIntelName$qv+304
	dw	0
	dw	5
	dd	0
	dd	0
	dw	0
	dw	5
	dd	0
	dd	@@_$DCFKB$@CpuInfo@determineOldIntelName$qv+320
	dw	488
	dw	5
	dd	0
	dd	@@_$DCFKB$@CpuInfo@determineOldIntelName$qv+336
	dw	488
	dw	5
	dd	0
	dd	0
@_$ECTGKB$@CpuInfo@determineOldIntelName$qv	ends
_DATA	ends
_TEXT	segment dword public use32 'CODE'
@CpuInfo@determineOldIntelName$qv	segment virtual
	align	2
@@CpuInfo@determineOldIntelName$qv	proc	near
?live16420@0:
@145:
	push      ebp
	mov       ebp,esp
	add       esp,-1276
	mov       eax,offset @@_$ECTGKB$@CpuInfo@determineOldIntelName$qv
	push      ebx
	push      esi
	push      edi
	mov       ebx,dword ptr [ebp+8]
	call      @__InitExceptBlockLDTC
?live16420@16: ; EBX = this
	mov       esi,offset $akalfgia
	lea       edi,dword ptr [ebp-924]
	mov       ecx,8
	rep   movsd
	push      ebx
	mov       eax,dword ptr [ebx]
	call      dword ptr [eax+60]
	pop       ecx
	cmp       eax,-2147483644
	jae       @147
	lea       edx,dword ptr [ebx+4]
	push      edx
	mov       ecx,dword ptr [ebx+4]
	call      dword ptr [ecx+16]
	pop       ecx
	sub       eax,4
	je        short @152
	dec       eax
	je        @151
	dec       eax
	je        @150
	jmp       @148
@152:
	lea       eax,dword ptr [ebx+4]
	push      eax
	mov       edx,dword ptr [ebx+4]
	call      dword ptr [edx+20]
	pop       ecx
	cmp       eax,8
	ja        @153
	jmp       dword ptr [@162+4*eax]
@162:
	dd        @161
	dd        @161
	dd        @160
	dd        @159
	dd        @158
	dd        @157
	dd        @153
	dd        @156
	dd        @155
@161:
	mov       word ptr [ebp-356],8
	lea       ecx,dword ptr [ebp-384]
	lea       eax,dword ptr [ebp-16]
	push      ecx
	push      offset s@+167
	push      eax
	call      @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$bctr$qpxcrx17std@%allocator$c%
	add       esp,12
	lea       edx,dword ptr [ebp-16]
	inc       dword ptr [ebp-344]
	lea       ecx,dword ptr [ebx+4]
	push      edx
	push      ecx
	mov       eax,dword ptr [ebx+4]
	call      dword ptr [eax+100]
	add       esp,8
	dec       dword ptr [ebp-344]
	cmp       dword ptr [ebp-8],0
	je        @173
	mov       edx,dword ptr [ebp-8]
	mov       ecx,dword ptr [edx-12]
	inc       ecx
	test      ecx,ecx
	je        short @168
	mov       esi,dword ptr [ebp-8]
	add       esi,-12
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @169
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @171
	push      esi
	call      @InterlockedDecrement
	mov       eax,dword ptr [esi]
	inc       eax
	jmp       short @170
@171:
	mov       eax,1
	jmp       short @170
@169:
	mov       eax,1
@170:
	test      eax,eax
	jne       @173
@168:
	mov       edx,dword ptr [ebp-8]
	add       edx,-12
	mov       dword ptr [ebp-388],edx
	mov       edi,dword ptr [ebp-8]
	add       edi,-12
	push      edi
	call      @$bdele$qpv
	pop       ecx
	xor       eax,eax
	mov       dword ptr [ebp-392],eax
	lea       ecx,dword ptr [ebp-16]
	mov       edx,dword ptr [ebp-392]
	mov       dword ptr [ebp-8],edx
	mov       dword ptr [ebp-396],ecx
	mov       eax,dword ptr [ebp-396]
	mov       edx,dword ptr [eax+8]
	mov       dword ptr [ebp-932],edx
	jmp       @173
@160:
	mov       word ptr [ebp-356],32
	lea       ecx,dword ptr [ebp-404]
	lea       eax,dword ptr [ebp-32]
	push      ecx
	push      offset s@+193
	push      eax
	call      @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$bctr$qpxcrx17std@%allocator$c%
	add       esp,12
	lea       edx,dword ptr [ebp-32]
	inc       dword ptr [ebp-344]
	lea       ecx,dword ptr [ebx+4]
	push      edx
	push      ecx
	mov       eax,dword ptr [ebx+4]
	call      dword ptr [eax+100]
	add       esp,8
	dec       dword ptr [ebp-344]
	cmp       dword ptr [ebp-24],0
	je        @173
	mov       edx,dword ptr [ebp-24]
	mov       ecx,dword ptr [edx-12]
	inc       ecx
	test      ecx,ecx
	je        short @178
	mov       esi,dword ptr [ebp-24]
	add       esi,-12
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @179
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @181
	push      esi
	call      @InterlockedDecrement
	mov       eax,dword ptr [esi]
	inc       eax
	jmp       short @180
@181:
	mov       eax,1
	jmp       short @180
@179:
	mov       eax,1
@180:
	test      eax,eax
	jne       @173
@178:
	mov       edx,dword ptr [ebp-24]
	add       edx,-12
	mov       dword ptr [ebp-408],edx
	mov       edi,dword ptr [ebp-24]
	add       edi,-12
	push      edi
	call      @$bdele$qpv
	pop       ecx
	xor       eax,eax
	mov       dword ptr [ebp-412],eax
	lea       ecx,dword ptr [ebp-32]
	mov       edx,dword ptr [ebp-412]
	mov       dword ptr [ebp-24],edx
	mov       dword ptr [ebp-416],ecx
	mov       eax,dword ptr [ebp-416]
	mov       edx,dword ptr [eax+8]
	mov       dword ptr [ebp-948],edx
	jmp       @173
@159:
	mov       word ptr [ebp-356],56
	lea       ecx,dword ptr [ebp-424]
	lea       eax,dword ptr [ebp-48]
	push      ecx
	push      offset s@+219
	push      eax
	call      @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$bctr$qpxcrx17std@%allocator$c%
	add       esp,12
	lea       edx,dword ptr [ebp-48]
	inc       dword ptr [ebp-344]
	lea       ecx,dword ptr [ebx+4]
	push      edx
	push      ecx
	mov       eax,dword ptr [ebx+4]
	call      dword ptr [eax+100]
	add       esp,8
	dec       dword ptr [ebp-344]
	cmp       dword ptr [ebp-40],0
	je        @173
	mov       edx,dword ptr [ebp-40]
	mov       ecx,dword ptr [edx-12]
	inc       ecx
	test      ecx,ecx
	je        short @187
	mov       esi,dword ptr [ebp-40]
	add       esi,-12
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @188
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @190
	push      esi
	call      @InterlockedDecrement
	mov       eax,dword ptr [esi]
	inc       eax
	jmp       short @189
@190:
	mov       eax,1
	jmp       short @189
@188:
	mov       eax,1
@189:
	test      eax,eax
	jne       @173
@187:
	mov       edx,dword ptr [ebp-40]
	add       edx,-12
	mov       dword ptr [ebp-428],edx
	mov       ecx,dword ptr [ebp-40]
	add       ecx,-12
	mov       dword ptr [ebp-432],ecx
	mov       eax,dword ptr [ebp-432]
	push      eax
	call      @$bdele$qpv
	pop       ecx
	xor       edx,edx
	mov       dword ptr [ebp-436],edx
	lea       eax,dword ptr [ebp-48]
	mov       ecx,dword ptr [ebp-436]
	mov       dword ptr [ebp-40],ecx
	mov       dword ptr [ebp-440],eax
	mov       edx,dword ptr [ebp-440]
	mov       ecx,dword ptr [edx+8]
	mov       dword ptr [ebp-964],ecx
	jmp       @173
@158:
	mov       word ptr [ebp-356],80
	lea       eax,dword ptr [ebp-448]
	lea       edx,dword ptr [ebp-64]
	push      eax
	push      offset s@+242
	push      edx
	call      @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$bctr$qpxcrx17std@%allocator$c%
	add       esp,12
	lea       ecx,dword ptr [ebp-64]
	inc       dword ptr [ebp-344]
	lea       eax,dword ptr [ebx+4]
	push      ecx
	push      eax
	mov       edx,dword ptr [ebx+4]
	call      dword ptr [edx+100]
	add       esp,8
	dec       dword ptr [ebp-344]
	cmp       dword ptr [ebp-56],0
	je        @173
	mov       ecx,dword ptr [ebp-56]
	mov       eax,dword ptr [ecx-12]
	inc       eax
	test      eax,eax
	je        short @196
	mov       esi,dword ptr [ebp-56]
	add       esi,-12
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @197
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @199
	push      esi
	call      @InterlockedDecrement
	mov       eax,dword ptr [esi]
	inc       eax
	jmp       short @198
@199:
	mov       eax,1
	jmp       short @198
@197:
	mov       eax,1
@198:
	test      eax,eax
	jne       @173
@196:
	mov       edx,dword ptr [ebp-56]
	add       edx,-12
	mov       dword ptr [ebp-452],edx
	mov       ecx,dword ptr [ebp-56]
	add       ecx,-12
	mov       dword ptr [ebp-456],ecx
	mov       eax,dword ptr [ebp-456]
	push      eax
	call      @$bdele$qpv
	pop       ecx
	xor       edx,edx
	mov       dword ptr [ebp-460],edx
	lea       eax,dword ptr [ebp-64]
	mov       ecx,dword ptr [ebp-460]
	mov       dword ptr [ebp-56],ecx
	mov       dword ptr [ebp-464],eax
	mov       edx,dword ptr [ebp-464]
	mov       ecx,dword ptr [edx+8]
	mov       dword ptr [ebp-980],ecx
	jmp       @173
@157:
	mov       word ptr [ebp-356],104
	lea       eax,dword ptr [ebp-472]
	lea       edx,dword ptr [ebp-80]
	push      eax
	push      offset s@+265
	push      edx
	call      @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$bctr$qpxcrx17std@%allocator$c%
	add       esp,12
	lea       ecx,dword ptr [ebp-80]
	inc       dword ptr [ebp-344]
	lea       eax,dword ptr [ebx+4]
	push      ecx
	push      eax
	mov       edx,dword ptr [ebx+4]
	call      dword ptr [edx+100]
	add       esp,8
	dec       dword ptr [ebp-344]
	cmp       dword ptr [ebp-72],0
	je        @173
	mov       ecx,dword ptr [ebp-72]
	mov       eax,dword ptr [ecx-12]
	inc       eax
	test      eax,eax
	je        short @205
	mov       esi,dword ptr [ebp-72]
	add       esi,-12
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @206
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @208
	push      esi
	call      @InterlockedDecrement
	mov       eax,dword ptr [esi]
	inc       eax
	jmp       short @207
@208:
	mov       eax,1
	jmp       short @207
@206:
	mov       eax,1
@207:
	test      eax,eax
	jne       @173
@205:
	mov       edx,dword ptr [ebp-72]
	add       edx,-12
	mov       dword ptr [ebp-476],edx
	mov       ecx,dword ptr [ebp-72]
	add       ecx,-12
	mov       dword ptr [ebp-480],ecx
	mov       eax,dword ptr [ebp-480]
	push      eax
	call      @$bdele$qpv
	pop       ecx
	xor       edx,edx
	mov       dword ptr [ebp-484],edx
	lea       eax,dword ptr [ebp-80]
	mov       ecx,dword ptr [ebp-484]
	mov       dword ptr [ebp-72],ecx
	mov       dword ptr [ebp-488],eax
	mov       edx,dword ptr [ebp-488]
	mov       ecx,dword ptr [edx+8]
	mov       dword ptr [ebp-996],ecx
	jmp       @173
@156:
	mov       word ptr [ebp-356],128
	lea       eax,dword ptr [ebp-496]
	lea       edx,dword ptr [ebp-96]
	push      eax
	push      offset s@+288
	push      edx
	call      @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$bctr$qpxcrx17std@%allocator$c%
	add       esp,12
	lea       ecx,dword ptr [ebp-96]
	inc       dword ptr [ebp-344]
	lea       eax,dword ptr [ebx+4]
	push      ecx
	push      eax
	mov       edx,dword ptr [ebx+4]
	call      dword ptr [edx+100]
	add       esp,8
	dec       dword ptr [ebp-344]
	cmp       dword ptr [ebp-88],0
	je        @173
	mov       ecx,dword ptr [ebp-88]
	mov       eax,dword ptr [ecx-12]
	inc       eax
	test      eax,eax
	je        short @214
	mov       esi,dword ptr [ebp-88]
	add       esi,-12
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @215
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @217
	push      esi
	call      @InterlockedDecrement
	mov       eax,dword ptr [esi]
	inc       eax
	jmp       short @216
@217:
	mov       eax,1
	jmp       short @216
@215:
	mov       eax,1
@216:
	test      eax,eax
	jne       @173
@214:
	mov       edx,dword ptr [ebp-88]
	add       edx,-12
	mov       dword ptr [ebp-500],edx
	mov       ecx,dword ptr [ebp-88]
	add       ecx,-12
	mov       dword ptr [ebp-504],ecx
	mov       eax,dword ptr [ebp-504]
	push      eax
	call      @$bdele$qpv
	pop       ecx
	xor       edx,edx
	mov       dword ptr [ebp-508],edx
	lea       eax,dword ptr [ebp-96]
	mov       ecx,dword ptr [ebp-508]
	mov       dword ptr [ebp-88],ecx
	mov       dword ptr [ebp-512],eax
	mov       edx,dword ptr [ebp-512]
	mov       ecx,dword ptr [edx+8]
	mov       dword ptr [ebp-1012],ecx
	jmp       @173
@155:
	mov       word ptr [ebp-356],152
	lea       eax,dword ptr [ebp-520]
	lea       edx,dword ptr [ebp-112]
	push      eax
	push      offset s@+330
	push      edx
	call      @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$bctr$qpxcrx17std@%allocator$c%
	add       esp,12
	lea       ecx,dword ptr [ebp-112]
	inc       dword ptr [ebp-344]
	lea       eax,dword ptr [ebx+4]
	push      ecx
	push      eax
	mov       edx,dword ptr [ebx+4]
	call      dword ptr [edx+100]
	add       esp,8
	dec       dword ptr [ebp-344]
	cmp       dword ptr [ebp-104],0
	je        @173
	mov       ecx,dword ptr [ebp-104]
	mov       eax,dword ptr [ecx-12]
	inc       eax
	test      eax,eax
	je        short @223
	mov       esi,dword ptr [ebp-104]
	add       esi,-12
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @224
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @226
	push      esi
	call      @InterlockedDecrement
	mov       eax,dword ptr [esi]
	inc       eax
	jmp       short @225
@226:
	mov       eax,1
	jmp       short @225
@224:
	mov       eax,1
@225:
	test      eax,eax
	jne       @173
@223:
	mov       edx,dword ptr [ebp-104]
	add       edx,-12
	mov       dword ptr [ebp-524],edx
	mov       ecx,dword ptr [ebp-104]
	add       ecx,-12
	mov       dword ptr [ebp-528],ecx
	mov       eax,dword ptr [ebp-528]
	push      eax
	call      @$bdele$qpv
	pop       ecx
	xor       edx,edx
	mov       dword ptr [ebp-532],edx
	lea       eax,dword ptr [ebp-112]
	mov       ecx,dword ptr [ebp-532]
	mov       dword ptr [ebp-104],ecx
	mov       dword ptr [ebp-536],eax
	mov       edx,dword ptr [ebp-536]
	mov       ecx,dword ptr [edx+8]
	mov       dword ptr [ebp-1028],ecx
	jmp       @173
@153:
	mov       word ptr [ebp-356],176
	lea       eax,dword ptr [ebp-544]
	lea       edx,dword ptr [ebp-128]
	push      eax
	push      offset s@+353
	push      edx
	call      @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$bctr$qpxcrx17std@%allocator$c%
	add       esp,12
	lea       ecx,dword ptr [ebp-128]
	inc       dword ptr [ebp-344]
	lea       eax,dword ptr [ebx+4]
	push      ecx
	push      eax
	mov       edx,dword ptr [ebx+4]
	call      dword ptr [edx+100]
	add       esp,8
	dec       dword ptr [ebp-344]
	cmp       dword ptr [ebp-120],0
	je        @173
	mov       ecx,dword ptr [ebp-120]
	mov       eax,dword ptr [ecx-12]
	inc       eax
	test      eax,eax
	je        short @232
	mov       esi,dword ptr [ebp-120]
	add       esi,-12
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @233
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @235
	push      esi
	call      @InterlockedDecrement
	mov       eax,dword ptr [esi]
	inc       eax
	jmp       short @234
@235:
	mov       eax,1
	jmp       short @234
@233:
	mov       eax,1
@234:
	test      eax,eax
	jne       @173
@232:
	mov       edx,dword ptr [ebp-120]
	add       edx,-12
	mov       dword ptr [ebp-548],edx
	mov       ecx,dword ptr [ebp-120]
	add       ecx,-12
	mov       dword ptr [ebp-552],ecx
	mov       eax,dword ptr [ebp-552]
	push      eax
	call      @$bdele$qpv
	pop       ecx
	xor       edx,edx
	mov       dword ptr [ebp-556],edx
	lea       eax,dword ptr [ebp-128]
	mov       ecx,dword ptr [ebp-556]
	mov       dword ptr [ebp-120],ecx
	mov       dword ptr [ebp-560],eax
	mov       edx,dword ptr [ebp-560]
	mov       ecx,dword ptr [edx+8]
	mov       dword ptr [ebp-1044],ecx
	jmp       @173
@151:
	mov       word ptr [ebp-356],200
	lea       eax,dword ptr [ebp-568]
	lea       edx,dword ptr [ebp-144]
	push      eax
	push      offset s@+373
	push      edx
	call      @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$bctr$qpxcrx17std@%allocator$c%
	add       esp,12
	lea       ecx,dword ptr [ebp-144]
	inc       dword ptr [ebp-344]
	lea       eax,dword ptr [ebx+4]
	push      ecx
	push      eax
	mov       edx,dword ptr [ebx+4]
	call      dword ptr [edx+100]
	add       esp,8
	dec       dword ptr [ebp-344]
	cmp       dword ptr [ebp-136],0
	je        @173
	mov       ecx,dword ptr [ebp-136]
	mov       eax,dword ptr [ecx-12]
	inc       eax
	test      eax,eax
	je        short @241
	mov       esi,dword ptr [ebp-136]
	add       esi,-12
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @242
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @244
	push      esi
	call      @InterlockedDecrement
	mov       eax,dword ptr [esi]
	inc       eax
	jmp       short @243
@244:
	mov       eax,1
	jmp       short @243
@242:
	mov       eax,1
@243:
	test      eax,eax
	jne       @173
@241:
	mov       edx,dword ptr [ebp-136]
	add       edx,-12
	mov       dword ptr [ebp-572],edx
	mov       edi,dword ptr [ebp-136]
	add       edi,-12
	push      edi
	call      @$bdele$qpv
	pop       ecx
	xor       eax,eax
	mov       dword ptr [ebp-576],eax
	lea       ecx,dword ptr [ebp-144]
	mov       edx,dword ptr [ebp-576]
	mov       dword ptr [ebp-136],edx
	mov       dword ptr [ebp-580],ecx
	mov       eax,dword ptr [ebp-580]
	mov       edx,dword ptr [eax+8]
	mov       dword ptr [ebp-1060],edx
	jmp       @173
@150:
	lea       ecx,dword ptr [ebx+4]
	push      ecx
	mov       eax,dword ptr [ebx+4]
	call      dword ptr [eax+20]
	pop       ecx
	cmp       eax,8
	ja        @246
	jmp       dword ptr [@253+4*eax]
@253:
	dd        @246
	dd        @252
	dd        @246
	dd        @251
	dd        @246
	dd        @249
	dd        @250
	dd        @249
	dd        @248
@252:
	mov       word ptr [ebp-356],224
	lea       edx,dword ptr [ebp-588]
	lea       ecx,dword ptr [ebp-160]
	push      edx
	push      offset s@+400
	push      ecx
	call      @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$bctr$qpxcrx17std@%allocator$c%
	add       esp,12
	lea       eax,dword ptr [ebp-160]
	inc       dword ptr [ebp-344]
	lea       edx,dword ptr [ebx+4]
	push      eax
	push      edx
	mov       ecx,dword ptr [ebx+4]
	call      dword ptr [ecx+100]
	add       esp,8
	dec       dword ptr [ebp-344]
	cmp       dword ptr [ebp-152],0
	je        @263
	mov       eax,dword ptr [ebp-152]
	mov       edx,dword ptr [eax-12]
	inc       edx
	test      edx,edx
	je        short @258
	mov       esi,dword ptr [ebp-152]
	add       esi,-12
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @259
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @261
	push      esi
	call      @InterlockedDecrement
	mov       eax,dword ptr [esi]
	inc       eax
	jmp       short @260
@261:
	mov       eax,1
	jmp       short @260
@259:
	mov       eax,1
@260:
	test      eax,eax
	jne       @263
@258:
	mov       edx,dword ptr [ebp-152]
	add       edx,-12
	mov       dword ptr [ebp-592],edx
	mov       edi,dword ptr [ebp-152]
	add       edi,-12
	push      edi
	call      @$bdele$qpv
	pop       ecx
	xor       eax,eax
	mov       dword ptr [ebp-596],eax
	lea       ecx,dword ptr [ebp-160]
	mov       edx,dword ptr [ebp-596]
	mov       dword ptr [ebp-152],edx
	mov       dword ptr [ebp-600],ecx
	mov       eax,dword ptr [ebp-600]
	mov       edx,dword ptr [eax+8]
	mov       dword ptr [ebp-1076],edx
	jmp       @263
@251:
	mov       word ptr [ebp-356],248
	lea       ecx,dword ptr [ebp-608]
	lea       eax,dword ptr [ebp-176]
	push      ecx
	push      offset s@+431
	push      eax
	call      @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$bctr$qpxcrx17std@%allocator$c%
	add       esp,12
	lea       edx,dword ptr [ebp-176]
	inc       dword ptr [ebp-344]
	lea       ecx,dword ptr [ebx+4]
	push      edx
	push      ecx
	mov       eax,dword ptr [ebx+4]
	call      dword ptr [eax+100]
	add       esp,8
	dec       dword ptr [ebp-344]
	cmp       dword ptr [ebp-168],0
	je        @263
	mov       edx,dword ptr [ebp-168]
	mov       ecx,dword ptr [edx-12]
	inc       ecx
	test      ecx,ecx
	je        short @268
	mov       esi,dword ptr [ebp-168]
	add       esi,-12
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @269
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @271
	push      esi
	call      @InterlockedDecrement
	mov       eax,dword ptr [esi]
	inc       eax
	jmp       short @270
@271:
	mov       eax,1
	jmp       short @270
@269:
	mov       eax,1
@270:
	test      eax,eax
	jne       @263
@268:
	mov       edx,dword ptr [ebp-168]
	add       edx,-12
	mov       dword ptr [ebp-612],edx
	mov       edi,dword ptr [ebp-168]
	add       edi,-12
	push      edi
	call      @$bdele$qpv
	pop       ecx
	xor       eax,eax
	mov       dword ptr [ebp-616],eax
	lea       ecx,dword ptr [ebp-176]
	mov       edx,dword ptr [ebp-616]
	mov       dword ptr [ebp-168],edx
	mov       dword ptr [ebp-620],ecx
	mov       eax,dword ptr [ebp-620]
	mov       edx,dword ptr [eax+8]
	mov       dword ptr [ebp-1092],edx
	jmp       @263
@249:
	mov       byte ptr [ebp-373],0
	mov       byte ptr [ebp-374],0
	push      1
	lea       ecx,dword ptr [ebp-374]
	push      ecx
	lea       eax,dword ptr [ebp-373]
	push      eax
	lea       edx,dword ptr [ebx+4]
	push      edx
	mov       ecx,dword ptr [ebx+4]
	call      dword ptr [ecx+64]
	pop       ecx
	push      eax
	push      ebx
	mov       eax,dword ptr [ebx]
	call      dword ptr [eax+76]
	add       esp,20
	lea       edx,dword ptr [ebp-374]
	lea       ecx,dword ptr [ebp-373]
	lea       eax,dword ptr [ebx+4]
	push      0
	push      edx
	push      ecx
	push      eax
	mov       edx,dword ptr [ebx+4]
	call      dword ptr [edx+68]
	pop       ecx
	push      eax
	push      ebx
	mov       ecx,dword ptr [ebx]
	call      dword ptr [ecx+76]
	add       esp,20
	lea       eax,dword ptr [ebp-374]
	lea       edx,dword ptr [ebp-373]
	lea       ecx,dword ptr [ebx+4]
	push      0
	push      eax
	push      edx
	push      ecx
	mov       eax,dword ptr [ebx+4]
	call      dword ptr [eax+72]
	pop       ecx
	push      eax
	push      ebx
	mov       edx,dword ptr [ebx]
	call      dword ptr [edx+76]
	add       esp,20
	lea       ecx,dword ptr [ebp-374]
	lea       eax,dword ptr [ebp-373]
	lea       edx,dword ptr [ebx+4]
	push      0
	push      ecx
	push      eax
	push      edx
	mov       ecx,dword ptr [ebx+4]
	call      dword ptr [ecx+76]
	pop       ecx
	push      eax
	push      ebx
	mov       eax,dword ptr [ebx]
	call      dword ptr [eax+76]
	add       esp,20
	cmp       byte ptr [ebp-373],0
	je        @273
	mov       word ptr [ebp-356],272
	lea       edx,dword ptr [ebp-628]
	lea       ecx,dword ptr [ebp-192]
	push      edx
	push      offset s@+470
	push      ecx
	call      @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$bctr$qpxcrx17std@%allocator$c%
	add       esp,12
	lea       eax,dword ptr [ebp-192]
	inc       dword ptr [ebp-344]
	lea       edx,dword ptr [ebx+4]
	push      eax
	push      edx
	mov       ecx,dword ptr [ebx+4]
	call      dword ptr [ecx+100]
	add       esp,8
	dec       dword ptr [ebp-344]
	cmp       dword ptr [ebp-184],0
	je        @263
	mov       eax,dword ptr [ebp-184]
	mov       edx,dword ptr [eax-12]
	inc       edx
	test      edx,edx
	je        short @278
	mov       esi,dword ptr [ebp-184]
	add       esi,-12
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @279
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @281
	push      esi
	call      @InterlockedDecrement
	mov       eax,dword ptr [esi]
	inc       eax
	jmp       short @280
@281:
	mov       eax,1
	jmp       short @280
@279:
	mov       eax,1
@280:
	test      eax,eax
	jne       @263
@278:
	mov       edx,dword ptr [ebp-184]
	add       edx,-12
	mov       dword ptr [ebp-632],edx
	mov       ecx,dword ptr [ebp-184]
	add       ecx,-12
	mov       dword ptr [ebp-636],ecx
	mov       eax,dword ptr [ebp-636]
	push      eax
	call      @$bdele$qpv
	pop       ecx
	xor       edx,edx
	mov       dword ptr [ebp-640],edx
	lea       eax,dword ptr [ebp-192]
	mov       ecx,dword ptr [ebp-640]
	mov       dword ptr [ebp-184],ecx
	mov       dword ptr [ebp-644],eax
	mov       edx,dword ptr [ebp-644]
	mov       ecx,dword ptr [edx+8]
	mov       dword ptr [ebp-1108],ecx
	jmp       @263
@273:
	cmp       byte ptr [ebp-374],0
	je        @283
	lea       eax,dword ptr [ebx+4]
	push      eax
	mov       edx,dword ptr [ebx+4]
	call      dword ptr [edx+20]
	pop       ecx
	cmp       eax,5
	jne       @284
	mov       word ptr [ebp-356],296
	lea       ecx,dword ptr [ebp-652]
	lea       eax,dword ptr [ebp-208]
	push      ecx
	push      offset s@+507
	push      eax
	call      @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$bctr$qpxcrx17std@%allocator$c%
	add       esp,12
	lea       edx,dword ptr [ebp-208]
	inc       dword ptr [ebp-344]
	lea       ecx,dword ptr [ebx+4]
	push      edx
	push      ecx
	mov       eax,dword ptr [ebx+4]
	call      dword ptr [eax+100]
	add       esp,8
	dec       dword ptr [ebp-344]
	cmp       dword ptr [ebp-200],0
	je        @263
	mov       edx,dword ptr [ebp-200]
	mov       ecx,dword ptr [edx-12]
	inc       ecx
	test      ecx,ecx
	je        short @289
	mov       esi,dword ptr [ebp-200]
	add       esi,-12
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @290
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @292
	push      esi
	call      @InterlockedDecrement
	mov       eax,dword ptr [esi]
	inc       eax
	jmp       short @291
@292:
	mov       eax,1
	jmp       short @291
@290:
	mov       eax,1
@291:
	test      eax,eax
	jne       @263
@289:
	mov       edx,dword ptr [ebp-200]
	add       edx,-12
	mov       dword ptr [ebp-656],edx
	mov       ecx,dword ptr [ebp-200]
	add       ecx,-12
	mov       dword ptr [ebp-660],ecx
	mov       eax,dword ptr [ebp-660]
	push      eax
	call      @$bdele$qpv
	pop       ecx
	xor       edx,edx
	mov       dword ptr [ebp-664],edx
	lea       eax,dword ptr [ebp-208]
	mov       ecx,dword ptr [ebp-664]
	mov       dword ptr [ebp-200],ecx
	mov       dword ptr [ebp-668],eax
	mov       edx,dword ptr [ebp-668]
	mov       ecx,dword ptr [edx+8]
	mov       dword ptr [ebp-1124],ecx
	jmp       @263
@284:
	mov       word ptr [ebp-356],320
	lea       eax,dword ptr [ebp-676]
	lea       edx,dword ptr [ebp-224]
	push      eax
	push      offset s@+546
	push      edx
	call      @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$bctr$qpxcrx17std@%allocator$c%
	add       esp,12
	lea       ecx,dword ptr [ebp-224]
	inc       dword ptr [ebp-344]
	lea       eax,dword ptr [ebx+4]
	push      ecx
	push      eax
	mov       edx,dword ptr [ebx+4]
	call      dword ptr [edx+100]
	add       esp,8
	dec       dword ptr [ebp-344]
	cmp       dword ptr [ebp-216],0
	je        @263
	mov       ecx,dword ptr [ebp-216]
	mov       eax,dword ptr [ecx-12]
	inc       eax
	test      eax,eax
	je        short @298
	mov       esi,dword ptr [ebp-216]
	add       esi,-12
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @299
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @301
	push      esi
	call      @InterlockedDecrement
	mov       eax,dword ptr [esi]
	inc       eax
	jmp       short @300
@301:
	mov       eax,1
	jmp       short @300
@299:
	mov       eax,1
@300:
	test      eax,eax
	jne       @263
@298:
	mov       edx,dword ptr [ebp-216]
	add       edx,-12
	mov       dword ptr [ebp-680],edx
	mov       ecx,dword ptr [ebp-216]
	add       ecx,-12
	mov       dword ptr [ebp-684],ecx
	mov       eax,dword ptr [ebp-684]
	push      eax
	call      @$bdele$qpv
	pop       ecx
	xor       edx,edx
	mov       dword ptr [ebp-688],edx
	lea       eax,dword ptr [ebp-224]
	mov       ecx,dword ptr [ebp-688]
	mov       dword ptr [ebp-216],ecx
	mov       dword ptr [ebp-692],eax
	mov       edx,dword ptr [ebp-692]
	mov       ecx,dword ptr [edx+8]
	mov       dword ptr [ebp-1140],ecx
	jmp       @263
@283:
	lea       eax,dword ptr [ebx+4]
	push      eax
	mov       edx,dword ptr [ebx+4]
	call      dword ptr [edx+20]
	pop       ecx
	cmp       eax,5
	jne       @303
	mov       word ptr [ebp-356],344
	lea       ecx,dword ptr [ebp-700]
	lea       eax,dword ptr [ebp-240]
	push      ecx
	push      offset s@+586
	push      eax
	call      @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$bctr$qpxcrx17std@%allocator$c%
	add       esp,12
	lea       edx,dword ptr [ebp-240]
	inc       dword ptr [ebp-344]
	lea       ecx,dword ptr [ebx+4]
	push      edx
	push      ecx
	mov       eax,dword ptr [ebx+4]
	call      dword ptr [eax+100]
	add       esp,8
	dec       dword ptr [ebp-344]
	cmp       dword ptr [ebp-232],0
	je        @263
	mov       edx,dword ptr [ebp-232]
	mov       ecx,dword ptr [edx-12]
	inc       ecx
	test      ecx,ecx
	je        short @308
	mov       esi,dword ptr [ebp-232]
	add       esi,-12
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @309
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @311
	push      esi
	call      @InterlockedDecrement
	mov       eax,dword ptr [esi]
	inc       eax
	jmp       short @310
@311:
	mov       eax,1
	jmp       short @310
@309:
	mov       eax,1
@310:
	test      eax,eax
	jne       @263
@308:
	mov       edx,dword ptr [ebp-232]
	add       edx,-12
	mov       dword ptr [ebp-704],edx
	mov       ecx,dword ptr [ebp-232]
	add       ecx,-12
	mov       dword ptr [ebp-708],ecx
	mov       eax,dword ptr [ebp-708]
	push      eax
	call      @$bdele$qpv
	pop       ecx
	xor       edx,edx
	mov       dword ptr [ebp-712],edx
	lea       eax,dword ptr [ebp-240]
	mov       ecx,dword ptr [ebp-712]
	mov       dword ptr [ebp-232],ecx
	mov       dword ptr [ebp-716],eax
	mov       edx,dword ptr [ebp-716]
	mov       ecx,dword ptr [edx+8]
	mov       dword ptr [ebp-1156],ecx
	jmp       @263
@303:
	mov       word ptr [ebp-356],368
	lea       eax,dword ptr [ebp-724]
	lea       edx,dword ptr [ebp-256]
	push      eax
	push      offset s@+625
	push      edx
	call      @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$bctr$qpxcrx17std@%allocator$c%
	add       esp,12
	lea       ecx,dword ptr [ebp-256]
	inc       dword ptr [ebp-344]
	lea       eax,dword ptr [ebx+4]
	push      ecx
	push      eax
	mov       edx,dword ptr [ebx+4]
	call      dword ptr [edx+100]
	add       esp,8
	dec       dword ptr [ebp-344]
	cmp       dword ptr [ebp-248],0
	je        @263
	mov       ecx,dword ptr [ebp-248]
	mov       eax,dword ptr [ecx-12]
	inc       eax
	test      eax,eax
	je        short @317
	mov       edx,dword ptr [ebp-248]
	add       edx,-12
	mov       dword ptr [ebp-728],edx
	mov       ecx,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	cmp       ecx,dword ptr [ebp-728]
	je        short @318
	mov       eax,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	cmp       eax,dword ptr [ebp-728]
	je        short @320
	mov       edx,dword ptr [ebp-728]
	push      edx
	call      @InterlockedDecrement
	mov       ecx,dword ptr [ebp-728]
	mov       eax,dword ptr [ecx]
	inc       eax
	jmp       short @319
@320:
	mov       eax,1
	jmp       short @319
@318:
	mov       eax,1
@319:
	test      eax,eax
	jne       @263
@317:
	mov       edx,dword ptr [ebp-248]
	add       edx,-12
	mov       dword ptr [ebp-732],edx
	mov       ecx,dword ptr [ebp-248]
	add       ecx,-12
	mov       dword ptr [ebp-736],ecx
	mov       eax,dword ptr [ebp-736]
	push      eax
	call      @$bdele$qpv
	pop       ecx
	xor       edx,edx
	mov       dword ptr [ebp-740],edx
	lea       eax,dword ptr [ebp-256]
	mov       ecx,dword ptr [ebp-740]
	mov       dword ptr [ebp-248],ecx
	mov       dword ptr [ebp-744],eax
	mov       edx,dword ptr [ebp-744]
	mov       ecx,dword ptr [edx+8]
	mov       dword ptr [ebp-1172],ecx
	jmp       @263
@250:
	mov       word ptr [ebp-356],392
	lea       eax,dword ptr [ebp-752]
	lea       edx,dword ptr [ebp-272]
	push      eax
	push      offset s@+656
	push      edx
	call      @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$bctr$qpxcrx17std@%allocator$c%
	add       esp,12
	lea       ecx,dword ptr [ebp-272]
	inc       dword ptr [ebp-344]
	lea       eax,dword ptr [ebx+4]
	push      ecx
	push      eax
	mov       edx,dword ptr [ebx+4]
	call      dword ptr [edx+100]
	add       esp,8
	dec       dword ptr [ebp-344]
	cmp       dword ptr [ebp-264],0
	je        @263
	mov       ecx,dword ptr [ebp-264]
	mov       eax,dword ptr [ecx-12]
	inc       eax
	test      eax,eax
	je        short @326
	mov       edx,dword ptr [ebp-264]
	add       edx,-12
	mov       dword ptr [ebp-756],edx
	mov       ecx,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	cmp       ecx,dword ptr [ebp-756]
	je        short @327
	mov       eax,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	cmp       eax,dword ptr [ebp-756]
	je        short @329
	mov       edx,dword ptr [ebp-756]
	push      edx
	call      @InterlockedDecrement
	mov       ecx,dword ptr [ebp-756]
	mov       eax,dword ptr [ecx]
	inc       eax
	jmp       short @328
@329:
	mov       eax,1
	jmp       short @328
@327:
	mov       eax,1
@328:
	test      eax,eax
	jne       @263
@326:
	mov       edx,dword ptr [ebp-264]
	add       edx,-12
	mov       dword ptr [ebp-760],edx
	mov       ecx,dword ptr [ebp-264]
	add       ecx,-12
	mov       dword ptr [ebp-764],ecx
	mov       eax,dword ptr [ebp-764]
	push      eax
	call      @$bdele$qpv
	pop       ecx
	xor       edx,edx
	mov       dword ptr [ebp-768],edx
	lea       eax,dword ptr [ebp-272]
	mov       ecx,dword ptr [ebp-768]
	mov       dword ptr [ebp-264],ecx
	mov       dword ptr [ebp-772],eax
	mov       edx,dword ptr [ebp-772]
	mov       ecx,dword ptr [edx+8]
	mov       dword ptr [ebp-1188],ecx
	jmp       @263
@248:
	mov       word ptr [ebp-356],416
	lea       eax,dword ptr [ebp-780]
	lea       edx,dword ptr [ebp-288]
	push      eax
	push      offset s@+693
	push      edx
	call      @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$bctr$qpxcrx17std@%allocator$c%
	add       esp,12
	lea       ecx,dword ptr [ebp-288]
	inc       dword ptr [ebp-344]
	lea       eax,dword ptr [ebx+4]
	push      ecx
	push      eax
	mov       edx,dword ptr [ebx+4]
	call      dword ptr [edx+100]
	add       esp,8
	dec       dword ptr [ebp-344]
	cmp       dword ptr [ebp-280],0
	je        @263
	mov       ecx,dword ptr [ebp-280]
	mov       eax,dword ptr [ecx-12]
	inc       eax
	test      eax,eax
	je        short @335
	mov       edx,dword ptr [ebp-280]
	add       edx,-12
	mov       dword ptr [ebp-784],edx
	mov       ecx,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	cmp       ecx,dword ptr [ebp-784]
	je        short @336
	mov       eax,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	cmp       eax,dword ptr [ebp-784]
	je        short @338
	mov       edx,dword ptr [ebp-784]
	push      edx
	call      @InterlockedDecrement
	mov       ecx,dword ptr [ebp-784]
	mov       eax,dword ptr [ecx]
	inc       eax
	jmp       short @337
@338:
	mov       eax,1
	jmp       short @337
@336:
	mov       eax,1
@337:
	test      eax,eax
	jne       @263
@335:
	mov       edx,dword ptr [ebp-280]
	add       edx,-12
	mov       dword ptr [ebp-788],edx
	mov       ecx,dword ptr [ebp-280]
	add       ecx,-12
	mov       dword ptr [ebp-792],ecx
	mov       eax,dword ptr [ebp-792]
	push      eax
	call      @$bdele$qpv
	pop       ecx
	xor       edx,edx
	mov       dword ptr [ebp-796],edx
	lea       eax,dword ptr [ebp-288]
	mov       ecx,dword ptr [ebp-796]
	mov       dword ptr [ebp-280],ecx
	mov       dword ptr [ebp-800],eax
	mov       edx,dword ptr [ebp-800]
	mov       ecx,dword ptr [edx+8]
	mov       dword ptr [ebp-1204],ecx
	jmp       @263
@246:
@340:
	xor       esi,esi
	lea       eax,dword ptr [ebp-924]
	mov       dword ptr [ebp-892],eax
	jmp       short @342
?live16420@848: ; EBX = this, ESI = brand_index
@341:
	inc       esi
	add       dword ptr [ebp-892],8
@342:
	cmp       esi,4
	jge       short @343
	lea       edx,dword ptr [ebx+4]
	push      edx
	mov       ecx,dword ptr [ebx+4]
	call      dword ptr [ecx+56]
	pop       ecx
	and       eax,255
	mov       edx,dword ptr [ebp-892]
	cmp       eax,dword ptr [edx]
	jne       short @341
@343:
	cmp       esi,4
	jge       @344
	mov       word ptr [ebp-356],440
	lea       eax,dword ptr [ebp-808]
	push      eax
	mov       ecx,dword ptr [ebp+8*esi-920]
	push      ecx
	lea       eax,dword ptr [ebp-304]
	push      eax
	call      @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$bctr$qpxcrx17std@%allocator$c%
	add       esp,12
	lea       edx,dword ptr [ebp-304]
	inc       dword ptr [ebp-344]
	lea       ecx,dword ptr [ebx+4]
	push      edx
	push      ecx
	mov       eax,dword ptr [ebx+4]
	call      dword ptr [eax+100]
	add       esp,8
	dec       dword ptr [ebp-344]
	cmp       dword ptr [ebp-296],0
	je        @263
	mov       edx,dword ptr [ebp-296]
	mov       ecx,dword ptr [edx-12]
	inc       ecx
	test      ecx,ecx
	je        short @349
	mov       eax,dword ptr [ebp-296]
	add       eax,-12
	mov       dword ptr [ebp-812],eax
	mov       edx,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	cmp       edx,dword ptr [ebp-812]
	je        short @350
	mov       ecx,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	cmp       ecx,dword ptr [ebp-812]
	je        short @352
	mov       eax,dword ptr [ebp-812]
	push      eax
	call      @InterlockedDecrement
	mov       edx,dword ptr [ebp-812]
	mov       ecx,dword ptr [edx]
	inc       ecx
	jmp       short @351
@352:
	mov       ecx,1
	jmp       short @351
@350:
	mov       ecx,1
@351:
	test      ecx,ecx
	jne       @263
@349:
	mov       eax,dword ptr [ebp-296]
	add       eax,-12
	mov       dword ptr [ebp-816],eax
	mov       edx,dword ptr [ebp-296]
	add       edx,-12
	mov       dword ptr [ebp-820],edx
	mov       eax,dword ptr [ebp-820]
	push      eax
	call      @$bdele$qpv
	pop       ecx
	xor       edx,edx
	mov       dword ptr [ebp-824],edx
	lea       eax,dword ptr [ebp-304]
	mov       ecx,dword ptr [ebp-824]
	mov       dword ptr [ebp-296],ecx
	mov       dword ptr [ebp-828],eax
	mov       edx,dword ptr [ebp-828]
	mov       ecx,dword ptr [edx+8]
	mov       dword ptr [ebp-1220],ecx
?live16420@912: ; EBX = this
	jmp       @263
@344:
	mov       word ptr [ebp-356],464
	lea       eax,dword ptr [ebp-836]
	lea       edx,dword ptr [ebp-320]
	push      eax
	push      offset s@+735
	push      edx
	call      @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$bctr$qpxcrx17std@%allocator$c%
	add       esp,12
	lea       ecx,dword ptr [ebp-320]
	inc       dword ptr [ebp-344]
	lea       eax,dword ptr [ebx+4]
	push      ecx
	push      eax
	mov       edx,dword ptr [ebx+4]
	call      dword ptr [edx+100]
	add       esp,8
	dec       dword ptr [ebp-344]
	cmp       dword ptr [ebp-312],0
	je        @263
	mov       ecx,dword ptr [ebp-312]
	mov       eax,dword ptr [ecx-12]
	inc       eax
	test      eax,eax
	je        short @358
	mov       edx,dword ptr [ebp-312]
	add       edx,-12
	mov       dword ptr [ebp-840],edx
	mov       ecx,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	cmp       ecx,dword ptr [ebp-840]
	je        short @359
	mov       eax,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	cmp       eax,dword ptr [ebp-840]
	je        short @361
	mov       edx,dword ptr [ebp-840]
	push      edx
	call      @InterlockedDecrement
	mov       ecx,dword ptr [ebp-840]
	mov       eax,dword ptr [ecx]
	inc       eax
	jmp       short @360
@361:
	mov       eax,1
	jmp       short @360
@359:
	mov       eax,1
@360:
	test      eax,eax
	jne       short @263
@358:
	mov       edx,dword ptr [ebp-312]
	add       edx,-12
	mov       dword ptr [ebp-844],edx
	mov       ecx,dword ptr [ebp-312]
	add       ecx,-12
	mov       dword ptr [ebp-848],ecx
	mov       eax,dword ptr [ebp-848]
	push      eax
	call      @$bdele$qpv
	pop       ecx
	xor       edx,edx
	mov       dword ptr [ebp-852],edx
	lea       eax,dword ptr [ebp-320]
	mov       ecx,dword ptr [ebp-852]
	mov       dword ptr [ebp-312],ecx
	mov       dword ptr [ebp-856],eax
	mov       edx,dword ptr [ebp-856]
	mov       ecx,dword ptr [edx+8]
	mov       dword ptr [ebp-1236],ecx
@363:
@263:
@148:
@173:
	mov       dword ptr [ebp-860],8388608
	lea       eax,dword ptr [ebp-860]
	lea       edx,dword ptr [ebx+4]
	push      eax
	push      edx
	mov       ecx,dword ptr [ebx+4]
	call      dword ptr [ecx+40]
	add       esp,8
	test      al,al
	je        @364
@365:
	mov       word ptr [ebp-356],500
	lea       eax,dword ptr [ebx+4]
	lea       edx,dword ptr [ebp-336]
	push      eax
	push      edx
	mov       ecx,dword ptr [ebx+4]
	call      dword ptr [ecx+28]
	add       esp,8
	inc       dword ptr [ebp-344]
	mov       word ptr [ebp-356],488
	mov       eax,dword ptr [ebp-328]
	mov       edx,dword ptr [eax-4]
	mov       dword ptr [ebp-864],edx
	push      offset s@+767
	call      @_strlen
	pop       ecx
	mov       dword ptr [ebp-868],eax
	mov       ecx,dword ptr [ebp-868]
	push      ecx
	push      0
	mov       eax,dword ptr [ebp-868]
	push      eax
	push      offset s@+767
	push      0
	mov       edx,dword ptr [ebp-864]
	push      edx
	lea       ecx,dword ptr [ebp-336]
	push      ecx
	call      @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@replace$quiuipxcuiuiui
	add       esp,28
	lea       eax,dword ptr [ebp-336]
	push      eax
	lea       edx,dword ptr [ebx+4]
	push      edx
	mov       ecx,dword ptr [ebx+4]
	call      dword ptr [ecx+100]
	add       esp,8
?live16420@1008: ; 
	dec       dword ptr [ebp-344]
	cmp       dword ptr [ebp-328],0
	je        @367
	mov       eax,dword ptr [ebp-328]
	mov       edx,dword ptr [eax-12]
	inc       edx
	test      edx,edx
	je        short @370
	mov       ecx,dword ptr [ebp-328]
	add       ecx,-12
	mov       dword ptr [ebp-872],ecx
	mov       eax,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	cmp       eax,dword ptr [ebp-872]
	je        short @371
	mov       edx,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	cmp       edx,dword ptr [ebp-872]
	je        short @373
	mov       ecx,dword ptr [ebp-872]
	push      ecx
	call      @InterlockedDecrement
	mov       eax,dword ptr [ebp-872]
	mov       edx,dword ptr [eax]
	inc       edx
	jmp       short @372
@373:
	mov       edx,1
	jmp       short @372
@371:
	mov       edx,1
@372:
	test      edx,edx
	jne       short @368
@370:
	mov       eax,dword ptr [ebp-328]
	add       eax,-12
	mov       dword ptr [ebp-876],eax
	mov       ecx,dword ptr [ebp-328]
	add       ecx,-12
	mov       dword ptr [ebp-880],ecx
	mov       eax,dword ptr [ebp-880]
	push      eax
	call      @$bdele$qpv
	pop       ecx
	xor       edx,edx
	mov       dword ptr [ebp-884],edx
	lea       eax,dword ptr [ebp-336]
	mov       ecx,dword ptr [ebp-884]
	mov       dword ptr [ebp-328],ecx
	mov       dword ptr [ebp-888],eax
	mov       edx,dword ptr [ebp-888]
	mov       ecx,dword ptr [edx+8]
	mov       dword ptr [ebp-1268],ecx
@368:
@369:
@367:
	mov       word ptr [ebp-356],0
@375:
@364:
@147:
	mov       eax,dword ptr [ebp-372]
	mov       dword ptr fs:[0],eax
@376:
	pop       edi
	pop       esi
	pop       ebx
	mov       esp,ebp
	pop       ebp
	ret 
@@CpuInfo@determineOldIntelName$qv	endp
@CpuInfo@determineOldIntelName$qv	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@CpuInfo@determineCeleronAndXeon$qulpot2o	segment virtual
	align	2
@@CpuInfo@determineCeleronAndXeon$qulpot2o	proc	near
?live16423@0:
@377:
	push      ebp
	mov       ebp,esp
	push      ebx
	mov       edx,dword ptr [ebp+12]
	mov       ebx,dword ptr [ebp+20]
?live16423@16: ; EDX = dwRegisterCache, ECX = pfIsCeleron, EBX = pfIsXeon
	mov       eax,edx
?live16423@32: ; 
	mov       ecx,dword ptr [ebp+16]
?live16423@48: ; EDX = dwRegisterCache, ECX = pfIsCeleron, EBX = pfIsXeon
	and       eax,-16777216
?live16423@64: ; EAX = dwCacheTemp, EDX = dwRegisterCache, ECX = pfIsCeleron, EBX = pfIsXeon
	;	
	cmp       eax,1073741824
	jne       short @378
	mov       byte ptr [ecx],1
@378:
	cmp       eax,1140850688
	jb        short @379
	cmp       eax,1157627904
	ja        short @379
?live16423@112: ; EDX = dwRegisterCache, ECX = pfIsCeleron, EBX = pfIsXeon
	mov       byte ptr [ebx],1
@379:
	mov       eax,edx
	and       eax,16711680
?live16423@144: ; EAX = dwCacheTemp, EDX = dwRegisterCache, ECX = pfIsCeleron, EBX = pfIsXeon
	;	
	cmp       eax,4194304
	jne       short @380
	mov       byte ptr [ecx],1
@380:
	cmp       eax,4456448
	jb        short @381
	cmp       eax,4521984
	ja        short @381
?live16423@192: ; EDX = dwRegisterCache, ECX = pfIsCeleron, EBX = pfIsXeon
	mov       byte ptr [ebx],1
@381:
	mov       eax,edx
	and       eax,65280
?live16423@224: ; EAX = dwCacheTemp, EDX = dwRegisterCache, ECX = pfIsCeleron, EBX = pfIsXeon
	;	
	cmp       eax,16384
	jne       short @382
	mov       byte ptr [ecx],1
@382:
	cmp       eax,17408
	jb        short @383
	cmp       eax,17664
	ja        short @383
?live16423@272: ; EDX = dwRegisterCache, ECX = pfIsCeleron, EBX = pfIsXeon
	mov       byte ptr [ebx],1
@383:
	cmp       byte ptr [ebp+24],0
	jne       short @384
	mov       eax,edx
	and       eax,255
?live16423@320: ; EAX = dwCacheTemp, ECX = pfIsCeleron, EBX = pfIsXeon
	cmp       eax,1073741824
	jne       short @385
	mov       byte ptr [ecx],1
?live16423@352: ; EAX = dwCacheTemp, EBX = pfIsXeon
@385:
	cmp       eax,1140850688
	jb        short @386
	cmp       eax,1157627904
	ja        short @386
?live16423@368: ; EBX = pfIsXeon
	mov       byte ptr [ebx],1
?live16423@384: ; 
@386:
@384:
@387:
	pop       ebx
	pop       ebp
	ret 
@@CpuInfo@determineCeleronAndXeon$qulpot2o	endp
@CpuInfo@determineCeleronAndXeon$qulpot2o	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@CpuInfo@calculateCpuSpeed$xqv	segment virtual
	align	2
@@CpuInfo@calculateCpuSpeed$xqv	proc	near
?live16424@0:
@388:
	push      ebp
	mov       ebp,esp
	push      ecx
	push      ebx
	push      esi
	push      edi
	mov       edi,dword ptr [ebp+8]
?live16424@16: ; EDI = this
	call      @timeGetTime
	mov       esi,eax
?live16424@32: ; ESI = nTimeStart, EDI = this
@389:
	call      @timeGetTime
	mov       ebx,eax
?live16424@48: ; EBX = nTimeStop, ESI = nTimeStart, EDI = this
	mov       eax,ebx
	sub       eax,esi
	dec       eax
	jle       short @389
?live16424@64: ; EBX = nTimeStop, EDI = this
	push      edi
	mov       edx,dword ptr [edi]
	call      dword ptr [edx+104]
	pop       ecx
	mov       dword ptr [ebp-4],eax
	mov       esi,ebx
?live16424@96: ; ESI = nTimeStart, EDI = this
@393:
	call      @timeGetTime
	mov       ebx,eax
?live16424@112: ; EBX = nTimeStop, ESI = nTimeStart, EDI = this
	sub       ebx,esi
	cmp       ebx,500
	jle       short @393
?live16424@128: ; EDI = this
	push      edi
	mov       eax,dword ptr [edi]
	call      dword ptr [eax+104]
	pop       ecx
?live16424@144: ; ECX = dwTotalTicks
	xor       edx,edx
?live16424@160: ; EAX = dwEndTicks
	mov       ecx,eax
	sub       ecx,dword ptr [ebp-4]
?live16424@176: ; ECX = dwTotalTicks
	mov       eax,ecx
	mov       ecx,500000
	div       ecx
?live16424@192: ; 
@398:
@397:
	pop       edi
	pop       esi
	pop       ebx
	pop       ecx
	pop       ebp
	ret 
@@CpuInfo@calculateCpuSpeed$xqv	endp
@CpuInfo@calculateCpuSpeed$xqv	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@CpuInfo@determineTimeStamp$xqv	segment virtual
	align	2
@@CpuInfo@determineTimeStamp$xqv	proc	near
?live16425@0:
	push      ebp
	mov       ebp,esp
	push      ecx
@399:
	mov	   dword ptr [ebp-4], eax
	mov       eax,dword ptr [ebp-4]
@401:
@400:
	pop       ecx
	pop       ebp
	ret 
@@CpuInfo@determineTimeStamp$xqv	endp
@CpuInfo@determineTimeStamp$xqv	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%	segment virtual
	align	2
@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%	label	byte
	dd	16
	dw	3
	dw	48
	dd	-1
	dd	3
	dw	120
	dw	124
	dd	0
	dw	0
	dw	0
	dd	0
	dd	1
	dd	1
	dd	@@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$bdtr$qv
	dw	1
	dw	128
	db	115
	db	116
	db	100
	db	58
	db	58
	db	98
	db	97
	db	115
	db	105
	db	99
	db	95
	db	115
	db	116
	db	114
	db	105
	db	110
	db	103
	db	60
	db	99
	db	104
	db	97
	db	114
	db	44
	db	115
	db	116
	db	100
	db	58
	db	58
	db	99
	db	104
	db	97
	db	114
	db	95
	db	116
	db	114
	db	97
	db	105
	db	116
	db	115
	db	60
	db	99
	db	104
	db	97
	db	114
	db	62
	db	44
	db	115
	db	116
	db	100
	db	58
	db	58
	db	97
	db	108
	db	108
	db	111
	db	99
	db	97
	db	116
	db	111
	db	114
	db	60
	db	99
	db	104
	db	97
	db	114
	db	62
	db	32
	db	62
	db	0
	db	0
	db	0
	db	0
	dd	0
	dd	0
	dd	0
@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@$xt$67std@%basic_ostringstream$c19std@%char_traits$c%17std@%allocator$c%%	segment virtual
	align	2
@@$xt$67std@%basic_ostringstream$c19std@%char_traits$c%17std@%allocator$c%%	label	byte
	dd	176
	dw	3
	dw	48
	dd	4
	dd	127
	dw	124
	dw	140
	dd	0
	dw	0
	dw	0
	dd	0
	dd	10
	dd	6
	dd	@@std@%basic_ostringstream$c19std@%char_traits$c%17std@%allocator$c%%@$bdtr$qv
	dw	1
	dw	156
	db	115
	db	116
	db	100
	db	58
	db	58
	db	98
	db	97
	db	115
	db	105
	db	99
	db	95
	db	111
	db	115
	db	116
	db	114
	db	105
	db	110
	db	103
	db	115
	db	116
	db	114
	db	101
	db	97
	db	109
	db	60
	db	99
	db	104
	db	97
	db	114
	db	44
	db	115
	db	116
	db	100
	db	58
	db	58
	db	99
	db	104
	db	97
	db	114
	db	95
	db	116
	db	114
	db	97
	db	105
	db	116
	db	115
	db	60
	db	99
	db	104
	db	97
	db	114
	db	62
	db	44
	db	115
	db	116
	db	100
	db	58
	db	58
	db	97
	db	108
	db	108
	db	111
	db	99
	db	97
	db	116
	db	111
	db	114
	db	60
	db	99
	db	104
	db	97
	db	114
	db	62
	db	32
	db	62
	db	0
	dd	@@$xt$42std@%basic_ostream$c19std@%char_traits$c%%
	dd	0
	dd	3
	dd	0
	dd	@@$xt$38std@%basic_ios$c19std@%char_traits$c%%
	dd	0
	dd	13
	dd	0
	dd	@@$xt$63std@%basic_stringbuf$c19std@%char_traits$c%17std@%allocator$c%%
	dd	12
	dd	0
@$xt$67std@%basic_ostringstream$c19std@%char_traits$c%17std@%allocator$c%%	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@$xt$p7CpuInfo	segment virtual
	align	2
@@$xt$p7CpuInfo	label	dword
	dd	4
	dw	16
	dw	12
	dd	@@$xt$7CpuInfo
	db	67
	db	112
	db	117
	db	73
	db	110
	db	102
	db	111
	db	32
	db	42
	db	0
@$xt$p7CpuInfo	ends
_TEXT	ends
_DATA	segment dword public use32 'DATA'
@CpuInfo@3	segment virtual
	align	2
@@CpuInfo@3	label	byte
	dd	@@$xt$7CpuInfo
	dd	0
	dd	0
	dd	@@CpuInfo@$bdtr$qv
	dd	@@CpuInfo@determineCpuInfo$qv
	dd	@@CpuInfo@determineCpuSpeed$qv
	dd	@@CpuInfo@getCpuIdentification$xqv
	dd	@@CpuInfo@getCpuSpeed$xqv
	dd	@@CpuInfo@getCpuSpeed$xqpul
	dd	@@CpuInfo@getNumProcessors$xqv
	dd	@@CpuInfo@getNumProcessors$xqpul
	dd	@@CpuInfo@getFamily$xqv
	dd	@@CpuInfo@getModel$xqv
	dd	@@CpuInfo@getStepping$xqv
	dd	@@CpuInfo@getStats$xqv
	dd	@@CpuInfo@assign$qrx7CpuInfo
	dd	@@CpuInfo@determineCpuId$qv
	dd	@@CpuInfo@determineCpuStats$qus
	dd	@@CpuInfo@determineHighestCpuId$qv
	dd	@@CpuInfo@determineCpuIdentification$qv
	dd	@@CpuInfo@determineIntelCacheInfo$qv
	dd	@@CpuInfo@determineOldIntelName$qv
	dd	@@CpuInfo@determineCeleronAndXeon$qulpot2o
	dd	@@CpuInfo@determineLargestExtendedFeature$qv
	dd	@@CpuInfo@determineExtendedFeature$qv
	dd	@@CpuInfo@determineNameString$qv
	dd	@@CpuInfo@determineAmdL1CacheInfo$qv
	dd	@@CpuInfo@determineAmdL2CacheInfo$qv
	dd	@@CpuInfo@calculateCpuSpeed$xqv
	dd	@@CpuInfo@determineTimeStamp$xqv
@CpuInfo@3	ends
_DATA	ends
_TEXT	segment dword public use32 'CODE'
@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$bdtr$qv	segment virtual
	align	2
@@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$bdtr$qv	proc	near
?live16440@0:
@402:
	push      ebp
	mov       ebp,esp
	add       esp,-28
	push      ebx
	push      esi
	push      edi
	mov       ebx,dword ptr [ebp+8]
	test      ebx,ebx
	je        short @403
?live16440@16: ; EBX = this
	cmp       dword ptr [ebx+8],0
	je        short @405
	mov       eax,dword ptr [ebx+8]
	mov       edx,dword ptr [eax-12]
	inc       edx
	test      edx,edx
	je        short @408
	mov       esi,dword ptr [ebx+8]
	add       esi,-12
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @409
	cmp       esi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @411
	push      esi
	call      @InterlockedDecrement
	mov       eax,dword ptr [esi]
	inc       eax
	jmp       short @410
@411:
	mov       eax,1
	jmp       short @410
@409:
	mov       eax,1
@410:
	test      eax,eax
	jne       short @406
@408:
	mov       edx,dword ptr [ebx+8]
	add       edx,-12
	mov       dword ptr [ebp-4],edx
	mov       edi,dword ptr [ebx+8]
	add       edi,-12
	push      edi
	call      @$bdele$qpv
	pop       ecx
	xor       eax,eax
	mov       dword ptr [ebp-8],eax
	mov       edx,dword ptr [ebp-8]
	mov       dword ptr [ebx+8],edx
	mov       dword ptr [ebp-12],ebx
	mov       ecx,dword ptr [ebp-12]
	mov       eax,dword ptr [ecx+8]
	mov       dword ptr [ebp-20],eax
@406:
@407:
@405:
	test      byte ptr [ebp+12],1
	je        short @413
	push      ebx
	call      @$bdele$qpv
	pop       ecx
?live16440@32: ; 
@413:
@403:
@414:
	pop       edi
	pop       esi
	pop       ebx
	mov       esp,ebp
	pop       ebp
	ret 
@@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$bdtr$qv	endp
@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$bdtr$qv	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@$xt$7CpuInfo	segment virtual
	align	2
@@$xt$7CpuInfo	label	byte
	dd	152
	dw	3
	dw	48
	dd	0
	dd	115
	dw	56
	dw	60
	dd	0
	dw	0
	dw	0
	dd	0
	dd	9
	dd	9
	dd	@@CpuInfo@$bdtr$qv
	dw	1
	dw	64
	db	67
	db	112
	db	117
	db	73
	db	110
	db	102
	db	111
	db	0
	dd	0
	dd	0
	dd	@@$xt$8CpuStats
	dd	4
	dd	@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	116
	dd	@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	132
	dd	0
@$xt$7CpuInfo	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@$xt$63std@%basic_stringbuf$c19std@%char_traits$c%17std@%allocator$c%%	segment virtual
	align	2
@@$xt$63std@%basic_stringbuf$c19std@%char_traits$c%17std@%allocator$c%%	label	byte
	dd	80
	dw	3
	dw	48
	dd	0
	dd	119
	dw	120
	dw	136
	dd	0
	dw	0
	dw	0
	dd	0
	dd	4
	dd	4
	dd	@@std@%basic_stringbuf$c19std@%char_traits$c%17std@%allocator$c%%@$bdtr$qv
	dw	1
	dw	140
	db	115
	db	116
	db	100
	db	58
	db	58
	db	98
	db	97
	db	115
	db	105
	db	99
	db	95
	db	115
	db	116
	db	114
	db	105
	db	110
	db	103
	db	98
	db	117
	db	102
	db	60
	db	99
	db	104
	db	97
	db	114
	db	44
	db	115
	db	116
	db	100
	db	58
	db	58
	db	99
	db	104
	db	97
	db	114
	db	95
	db	116
	db	114
	db	97
	db	105
	db	116
	db	115
	db	60
	db	99
	db	104
	db	97
	db	114
	db	62
	db	44
	db	115
	db	116
	db	100
	db	58
	db	58
	db	97
	db	108
	db	108
	db	111
	db	99
	db	97
	db	116
	db	111
	db	114
	db	60
	db	99
	db	104
	db	97
	db	114
	db	62
	db	32
	db	62
	db	0
	dd	@@$xt$44std@%basic_streambuf$c19std@%char_traits$c%%
	dd	0
	dd	3
	dd	0
	dd	0
	dd	0
@$xt$63std@%basic_stringbuf$c19std@%char_traits$c%17std@%allocator$c%%	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@$xt$38std@%basic_ios$c19std@%char_traits$c%%	segment virtual
	align	2
@@$xt$38std@%basic_ios$c19std@%char_traits$c%%	label	byte
	dd	84
	dw	3
	dw	48
	dd	0
	dd	119
	dw	96
	dw	112
	dd	0
	dw	0
	dw	0
	dd	0
	dd	4
	dd	4
	dd	@@std@%basic_ios$c19std@%char_traits$c%%@$bdtr$qv
	dw	1
	dw	116
	db	115
	db	116
	db	100
	db	58
	db	58
	db	98
	db	97
	db	115
	db	105
	db	99
	db	95
	db	105
	db	111
	db	115
	db	60
	db	99
	db	104
	db	97
	db	114
	db	44
	db	115
	db	116
	db	100
	db	58
	db	58
	db	99
	db	104
	db	97
	db	114
	db	95
	db	116
	db	114
	db	97
	db	105
	db	116
	db	115
	db	60
	db	99
	db	104
	db	97
	db	114
	db	62
	db	32
	db	62
	db	0
	db	0
	db	0
	db	0
	dd	@@$xt$12std@ios_base
	dd	0
	dd	3
	dd	0
	dd	0
	dd	0
@$xt$38std@%basic_ios$c19std@%char_traits$c%%	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@$xt$42std@%basic_ostream$c19std@%char_traits$c%%	segment virtual
	align	2
@@$xt$42std@%basic_ostream$c19std@%char_traits$c%%	label	byte
	dd	96
	dw	3
	dw	48
	dd	4
	dd	127
	dw	100
	dw	104
	dd	0
	dw	0
	dw	0
	dd	0
	dd	5
	dd	1
	dd	@@std@%basic_ostream$c19std@%char_traits$c%%@$bdtr$qv
	dw	1
	dw	120
	db	115
	db	116
	db	100
	db	58
	db	58
	db	98
	db	97
	db	115
	db	105
	db	99
	db	95
	db	111
	db	115
	db	116
	db	114
	db	101
	db	97
	db	109
	db	60
	db	99
	db	104
	db	97
	db	114
	db	44
	db	115
	db	116
	db	100
	db	58
	db	58
	db	99
	db	104
	db	97
	db	114
	db	95
	db	116
	db	114
	db	97
	db	105
	db	116
	db	115
	db	60
	db	99
	db	104
	db	97
	db	114
	db	62
	db	32
	db	62
	db	0
	db	0
	db	0
	db	0
	dd	0
	dd	@@$xt$38std@%basic_ios$c19std@%char_traits$c%%
	dd	0
	dd	7
	dd	0
	dd	0
@$xt$42std@%basic_ostream$c19std@%char_traits$c%%	ends
_TEXT	ends
_DATA	segment dword public use32 'DATA'
@_$DCHKB$@CpuInfo@getCpuIdentification$xqv	segment virtual
	align	2
@@_$DCHKB$@CpuInfo@getCpuIdentification$xqv	label	dword
	dd	@@$xt$p60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	20
	dd	8
	dd	0
@_$DCHKB$@CpuInfo@getCpuIdentification$xqv	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@_$ECTIKB$@CpuInfo@getCpuIdentification$xqv	segment virtual
	align	2
@@_$ECTIKB$@CpuInfo@getCpuIdentification$xqv	label	dword
	dd	0
	dd	-36
	dw	0
	dw	5
	dd	0
	dd	@@_$DCHKB$@CpuInfo@getCpuIdentification$xqv
@_$ECTIKB$@CpuInfo@getCpuIdentification$xqv	ends
_DATA	ends
_TEXT	segment dword public use32 'CODE'
@CpuInfo@getCpuIdentification$xqv	segment virtual
	align	2
@@CpuInfo@getCpuIdentification$xqv	proc	near
?live16431@0:
@415:
	push      ebp
	mov       ebp,esp
	add       esp,-36
	mov       eax,offset @@_$ECTIKB$@CpuInfo@getCpuIdentification$xqv
	push      ebx
	mov       ebx,dword ptr [ebp+12]
	call      @__InitExceptBlockLDTC
?live16431@16: ; EBX = this
	mov       word ptr [ebp-20],8
	lea       edx,dword ptr [ebx+4]
	push      edx
	mov       ecx,dword ptr [ebp+8]
	push      ecx
	mov       eax,dword ptr [ebx+4]
	call      dword ptr [eax+28]
	add       esp,8
	mov       eax,dword ptr [ebp+8]
	inc       dword ptr [ebp-8]
	mov       edx,dword ptr [ebp-36]
	mov       dword ptr fs:[0],edx
?live16431@32: ; 
@417:
@416:
	pop       ebx
	mov       esp,ebp
	pop       ebp
	ret 
@@CpuInfo@getCpuIdentification$xqv	endp
@CpuInfo@getCpuIdentification$xqv	ends
_TEXT	ends
_DATA	segment dword public use32 'DATA'
@_$DCJKB$@CpuInfo@getCpuSpeed$xqv	segment virtual
	align	2
@@_$DCJKB$@CpuInfo@getCpuSpeed$xqv	label	dword
	dd	@@$xt$p60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	20
	dd	8
	dd	0
@_$DCJKB$@CpuInfo@getCpuSpeed$xqv	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@_$ECTKKB$@CpuInfo@getCpuSpeed$xqv	segment virtual
	align	2
@@_$ECTKKB$@CpuInfo@getCpuSpeed$xqv	label	dword
	dd	0
	dd	-36
	dw	0
	dw	5
	dd	0
	dd	@@_$DCJKB$@CpuInfo@getCpuSpeed$xqv
	dw	8
	dw	5
	dd	0
	dd	0
@_$ECTKKB$@CpuInfo@getCpuSpeed$xqv	ends
_DATA	ends
_TEXT	segment dword public use32 'CODE'
@CpuInfo@getCpuSpeed$xqv	segment virtual
	align	2
@@CpuInfo@getCpuSpeed$xqv	proc	near
?live16432@0:
@418:
	push      ebp
	mov       ebp,esp
	add       esp,-104
	mov       eax,offset @@_$ECTKKB$@CpuInfo@getCpuSpeed$xqv
	push      ebx
	push      esi
	push      edi
	call      @__InitExceptBlockLDTC
	mov       word ptr [ebp-20],8
	mov       ebx,dword ptr [ebp+12]
	xor       eax,eax
	mov       dword ptr [ebp-40],eax
	add       ebx,116
	mov       edx,dword ptr [ebp+8]
	mov       ecx,dword ptr [ebp-40]
	mov       dword ptr [edx+8],ecx
	mov       eax,dword ptr [ebx+8]
	mov       edx,dword ptr [eax-12]
	inc       edx
	test      edx,edx
	jle       short @419
	mov       ecx,dword ptr [ebx+8]
	mov       dword ptr [ebp-44],ecx
	mov       eax,dword ptr [ebp+8]
	mov       edx,dword ptr [ebp-44]
	mov       dword ptr [eax+8],edx
	mov       ecx,dword ptr [ebp+8]
	mov       dword ptr [ebp-48],ecx
	mov       eax,dword ptr [ebp-48]
	mov       edx,dword ptr [eax+8]
	mov       dword ptr [ebp-80],edx
	mov       ecx,dword ptr [ebp+8]
	mov       edi,dword ptr [ecx+8]
	add       edi,-12
	cmp       edi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @420
	push      edi
	call      @InterlockedIncrement
	jmp       short @420
@419:
	mov       eax,dword ptr [ebx+8]
	mov       esi,dword ptr [eax-4]
	push      esi
	push      esi
	mov       edx,dword ptr [ebp+8]
	push      edx
	call      @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__getRep$quiui
	add       esp,12
	mov       dword ptr [ebp-56],eax
	mov       ecx,dword ptr [ebp-56]
	add       ecx,12
	mov       dword ptr [ebp-52],ecx
	mov       eax,dword ptr [ebp+8]
	mov       edx,dword ptr [ebp-52]
	mov       dword ptr [eax+8],edx
	mov       ecx,dword ptr [ebp+8]
	mov       dword ptr [ebp-60],ecx
	mov       eax,dword ptr [ebp-60]
	mov       edx,dword ptr [eax+8]
	mov       dword ptr [ebp-96],edx
	mov       dword ptr [ebp-64],esi
	mov       ecx,dword ptr [ebx+8]
	mov       dword ptr [ebp-68],ecx
	mov       eax,dword ptr [ebp+8]
	mov       edx,dword ptr [eax+8]
	mov       dword ptr [ebp-72],edx
	mov       ecx,dword ptr [ebp-64]
	push      ecx
	mov       eax,dword ptr [ebp-68]
	push      eax
	mov       edx,dword ptr [ebp-72]
	push      edx
	call      @_memcpy
	add       esp,12
@420:
	inc       dword ptr [ebp-8]
	mov       eax,dword ptr [ebp+8]
	inc       dword ptr [ebp-8]
	mov       edx,dword ptr [ebp-36]
	mov       dword ptr fs:[0],edx
@424:
@423:
	pop       edi
	pop       esi
	pop       ebx
	mov       esp,ebp
	pop       ebp
	ret 
@@CpuInfo@getCpuSpeed$xqv	endp
@CpuInfo@getCpuSpeed$xqv	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@CpuInfo@getCpuSpeed$xqpul	segment virtual
	align	2
@@CpuInfo@getCpuSpeed$xqpul	proc	near
?live16433@0:
@425:
	push      ebp
	mov       ebp,esp
	push      ebx
	push      esi
	mov       ebx,dword ptr [ebp+8]
?live16433@16: ; EBX = this
	mov       esi,dword ptr [ebx+124]
	push      esi
	call      @_atol
	pop       ecx
	mov       edx,dword ptr [ebp+12]
	mov       dword ptr [edx],eax
?live16433@32: ; 
@426:
	pop       esi
	pop       ebx
	pop       ebp
	ret 
@@CpuInfo@getCpuSpeed$xqpul	endp
@CpuInfo@getCpuSpeed$xqpul	ends
_TEXT	ends
_DATA	segment dword public use32 'DATA'
@_$DCLKB$@CpuInfo@getNumProcessors$xqv	segment virtual
	align	2
@@_$DCLKB$@CpuInfo@getNumProcessors$xqv	label	dword
	dd	@@$xt$p60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	20
	dd	8
	dd	0
@_$DCLKB$@CpuInfo@getNumProcessors$xqv	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@_$ECTMKB$@CpuInfo@getNumProcessors$xqv	segment virtual
	align	2
@@_$ECTMKB$@CpuInfo@getNumProcessors$xqv	label	dword
	dd	0
	dd	-36
	dw	0
	dw	5
	dd	0
	dd	@@_$DCLKB$@CpuInfo@getNumProcessors$xqv
	dw	8
	dw	5
	dd	0
	dd	0
@_$ECTMKB$@CpuInfo@getNumProcessors$xqv	ends
_DATA	ends
_TEXT	segment dword public use32 'CODE'
@CpuInfo@getNumProcessors$xqv	segment virtual
	align	2
@@CpuInfo@getNumProcessors$xqv	proc	near
?live16434@0:
@427:
	push      ebp
	mov       ebp,esp
	add       esp,-104
	mov       eax,offset @@_$ECTMKB$@CpuInfo@getNumProcessors$xqv
	push      ebx
	push      esi
	push      edi
	call      @__InitExceptBlockLDTC
	mov       word ptr [ebp-20],8
	mov       ebx,dword ptr [ebp+12]
	xor       eax,eax
	mov       dword ptr [ebp-40],eax
	add       ebx,132
	mov       edx,dword ptr [ebp+8]
	mov       ecx,dword ptr [ebp-40]
	mov       dword ptr [edx+8],ecx
	mov       eax,dword ptr [ebx+8]
	mov       edx,dword ptr [eax-12]
	inc       edx
	test      edx,edx
	jle       short @428
	mov       ecx,dword ptr [ebx+8]
	mov       dword ptr [ebp-44],ecx
	mov       eax,dword ptr [ebp+8]
	mov       edx,dword ptr [ebp-44]
	mov       dword ptr [eax+8],edx
	mov       ecx,dword ptr [ebp+8]
	mov       dword ptr [ebp-48],ecx
	mov       eax,dword ptr [ebp-48]
	mov       edx,dword ptr [eax+8]
	mov       dword ptr [ebp-80],edx
	mov       ecx,dword ptr [ebp+8]
	mov       edi,dword ptr [ecx+8]
	add       edi,-12
	cmp       edi,offset @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
	je        short @429
	push      edi
	call      @InterlockedIncrement
	jmp       short @429
@428:
	mov       eax,dword ptr [ebx+8]
	mov       esi,dword ptr [eax-4]
	push      esi
	push      esi
	mov       edx,dword ptr [ebp+8]
	push      edx
	call      @@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__getRep$quiui
	add       esp,12
	mov       dword ptr [ebp-56],eax
	mov       ecx,dword ptr [ebp-56]
	add       ecx,12
	mov       dword ptr [ebp-52],ecx
	mov       eax,dword ptr [ebp+8]
	mov       edx,dword ptr [ebp-52]
	mov       dword ptr [eax+8],edx
	mov       ecx,dword ptr [ebp+8]
	mov       dword ptr [ebp-60],ecx
	mov       eax,dword ptr [ebp-60]
	mov       edx,dword ptr [eax+8]
	mov       dword ptr [ebp-96],edx
	mov       dword ptr [ebp-64],esi
	mov       ecx,dword ptr [ebx+8]
	mov       dword ptr [ebp-68],ecx
	mov       eax,dword ptr [ebp+8]
	mov       edx,dword ptr [eax+8]
	mov       dword ptr [ebp-72],edx
	mov       ecx,dword ptr [ebp-64]
	push      ecx
	mov       eax,dword ptr [ebp-68]
	push      eax
	mov       edx,dword ptr [ebp-72]
	push      edx
	call      @_memcpy
	add       esp,12
@429:
	inc       dword ptr [ebp-8]
	mov       eax,dword ptr [ebp+8]
	inc       dword ptr [ebp-8]
	mov       edx,dword ptr [ebp-36]
	mov       dword ptr fs:[0],edx
@433:
@432:
	pop       edi
	pop       esi
	pop       ebx
	mov       esp,ebp
	pop       ebp
	ret 
@@CpuInfo@getNumProcessors$xqv	endp
@CpuInfo@getNumProcessors$xqv	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@CpuInfo@getNumProcessors$xqpul	segment virtual
	align	2
@@CpuInfo@getNumProcessors$xqpul	proc	near
?live16435@0:
@434:
	push      ebp
	mov       ebp,esp
	push      ebx
	push      esi
	mov       ebx,dword ptr [ebp+8]
?live16435@16: ; EBX = this
	mov       esi,dword ptr [ebx+140]
	push      esi
	call      @_atol
	pop       ecx
	mov       edx,dword ptr [ebp+12]
	mov       dword ptr [edx],eax
?live16435@32: ; 
@435:
	pop       esi
	pop       ebx
	pop       ebp
	ret 
@@CpuInfo@getNumProcessors$xqpul	endp
@CpuInfo@getNumProcessors$xqpul	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@CpuInfo@getFamily$xqv	segment virtual
	align	2
@@CpuInfo@getFamily$xqv	proc	near
?live16436@0:
@436:
	push      ebp
	mov       ebp,esp
	push      ebx
	mov       ebx,dword ptr [ebp+8]
?live16436@16: ; EBX = this
	lea       eax,dword ptr [ebx+4]
	push      eax
	mov       edx,dword ptr [ebx+4]
	call      dword ptr [edx+16]
	pop       ecx
?live16436@32: ; 
@438:
@437:
	pop       ebx
	pop       ebp
	ret 
@@CpuInfo@getFamily$xqv	endp
@CpuInfo@getFamily$xqv	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@CpuInfo@getModel$xqv	segment virtual
	align	2
@@CpuInfo@getModel$xqv	proc	near
?live16437@0:
@439:
	push      ebp
	mov       ebp,esp
	push      ebx
	mov       ebx,dword ptr [ebp+8]
?live16437@16: ; EBX = this
	lea       eax,dword ptr [ebx+4]
	push      eax
	mov       edx,dword ptr [ebx+4]
	call      dword ptr [edx+20]
	pop       ecx
?live16437@32: ; 
@441:
@440:
	pop       ebx
	pop       ebp
	ret 
@@CpuInfo@getModel$xqv	endp
@CpuInfo@getModel$xqv	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@CpuInfo@getStepping$xqv	segment virtual
	align	2
@@CpuInfo@getStepping$xqv	proc	near
?live16438@0:
@442:
	push      ebp
	mov       ebp,esp
	push      ebx
	mov       ebx,dword ptr [ebp+8]
?live16438@16: ; EBX = this
	lea       eax,dword ptr [ebx+4]
	push      eax
	mov       edx,dword ptr [ebx+4]
	call      dword ptr [edx+24]
	pop       ecx
?live16438@32: ; 
@444:
@443:
	pop       ebx
	pop       ebp
	ret 
@@CpuInfo@getStepping$xqv	endp
@CpuInfo@getStepping$xqv	ends
_TEXT	ends
_DATA	segment dword public use32 'DATA'
@_$DCNKB$@CpuInfo@getStats$xqv	segment virtual
	align	2
@@_$DCNKB$@CpuInfo@getStats$xqv	label	dword
	dd	@@$xt$p8CpuStats
	dd	20
	dd	8
	dd	0
@_$DCNKB$@CpuInfo@getStats$xqv	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@_$ECTOKB$@CpuInfo@getStats$xqv	segment virtual
	align	2
@@_$ECTOKB$@CpuInfo@getStats$xqv	label	dword
	dd	0
	dd	-36
	dw	0
	dw	5
	dd	0
	dd	@@_$DCNKB$@CpuInfo@getStats$xqv
@_$ECTOKB$@CpuInfo@getStats$xqv	ends
_DATA	ends
_TEXT	segment dword public use32 'CODE'
@CpuInfo@getStats$xqv	segment virtual
	align	2
@@CpuInfo@getStats$xqv	proc	near
?live16439@0:
@445:
	push      ebp
	mov       ebp,esp
	add       esp,-36
	mov       eax,offset @@_$ECTOKB$@CpuInfo@getStats$xqv
	push      ebx
	mov       ebx,dword ptr [ebp+12]
	call      @__InitExceptBlockLDTC
?live16439@16: ; EBX = this
	mov       word ptr [ebp-20],8
	add       ebx,4
	push      ebx
	mov       eax,dword ptr [ebp+8]
	push      eax
	call      @@CpuStats@$bctr$qrx8CpuStats
	add       dword ptr [ebp-8],6
	mov       eax,dword ptr [ebp+8]
	add       esp,8
	add       dword ptr [ebp-8],6
	mov       edx,dword ptr [ebp-36]
	mov       dword ptr fs:[0],edx
?live16439@32: ; 
@447:
@446:
	pop       ebx
	mov       esp,ebp
	pop       ebp
	ret 
@@CpuInfo@getStats$xqv	endp
@CpuInfo@getStats$xqv	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@$xt$p8CpuStats	segment virtual
	align	2
@@$xt$p8CpuStats	label	dword
	dd	4
	dw	16
	dw	12
	dd	@@$xt$8CpuStats
	db	67
	db	112
	db	117
	db	83
	db	116
	db	97
	db	116
	db	115
	db	32
	db	42
	db	0
@$xt$p8CpuStats	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@$xt$p60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%	segment virtual
	align	2
@@$xt$p60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%	label	dword
	dd	4
	dw	16
	dw	12
	dd	@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	db	115
	db	116
	db	114
	db	105
	db	110
	db	103
	db	32
	db	42
	db	0
@$xt$p60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@$xt$12std@ios_base	segment virtual
	align	2
@@$xt$12std@ios_base	label	byte
	dd	64
	dw	3
	dw	48
	dd	0
	dd	115
	dw	64
	dw	68
	dd	0
	dw	0
	dw	0
	dd	0
	dd	3
	dd	3
	dd	@@std@ios_base@$bdtr$qv
	dw	1
	dw	72
	db	115
	db	116
	db	100
	db	58
	db	58
	db	105
	db	111
	db	115
	db	95
	db	98
	db	97
	db	115
	db	101
	db	0
	db	0
	db	0
	dd	0
	dd	0
	dd	@@$xt$11_RWSTDMutex
	dd	16
	dd	@@$xt$10std@locale
	dd	44
	dd	0
@$xt$12std@ios_base	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@$xt$44std@%basic_streambuf$c19std@%char_traits$c%%	segment virtual
	align	2
@@$xt$44std@%basic_streambuf$c19std@%char_traits$c%%	label	byte
	dd	68
	dw	3
	dw	48
	dd	0
	dd	115
	dw	100
	dw	104
	dd	0
	dw	0
	dw	0
	dd	0
	dd	3
	dd	3
	dd	@@std@%basic_streambuf$c19std@%char_traits$c%%@$bdtr$qv
	dw	1
	dw	108
	db	115
	db	116
	db	100
	db	58
	db	58
	db	98
	db	97
	db	115
	db	105
	db	99
	db	95
	db	115
	db	116
	db	114
	db	101
	db	97
	db	109
	db	98
	db	117
	db	102
	db	60
	db	99
	db	104
	db	97
	db	114
	db	44
	db	115
	db	116
	db	100
	db	58
	db	58
	db	99
	db	104
	db	97
	db	114
	db	95
	db	116
	db	114
	db	97
	db	105
	db	116
	db	115
	db	60
	db	99
	db	104
	db	97
	db	114
	db	62
	db	32
	db	62
	db	0
	db	0
	dd	0
	dd	0
	dd	@@$xt$11_RWSTDMutex
	dd	4
	dd	@@$xt$10std@locale
	dd	60
	dd	0
@$xt$44std@%basic_streambuf$c19std@%char_traits$c%%	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@$xt$8CpuStats	segment virtual
	align	2
@@$xt$8CpuStats	label	byte
	dd	112
	dw	3
	dw	48
	dd	0
	dd	115
	dw	60
	dw	64
	dd	0
	dw	0
	dw	0
	dd	0
	dd	6
	dd	6
	dd	@@CpuStats@$bdtr$qv
	dw	1
	dw	68
	db	67
	db	112
	db	117
	db	83
	db	116
	db	97
	db	116
	db	115
	db	0
	db	0
	db	0
	db	0
	dd	0
	dd	0
	dd	@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	12
	dd	@@$xt$60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
	dd	28
	dd	@@$xt$14RegisterValues
	dd	48
	dd	@@$xt$14RegisterValues
	dd	68
	dd	@@$xt$14RegisterValues
	dd	88
	dd	0
@$xt$8CpuStats	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@$xt$14RegisterValues	segment virtual
	align	2
@@$xt$14RegisterValues	label	byte
	dd	20
	dw	3
	dw	48
	dd	0
	dd	115
	dw	64
	dw	68
	dd	0
	dw	0
	dw	0
	dd	0
	dd	1
	dd	1
	dd	@@RegisterValues@$bdtr$qv
	dw	1
	dw	72
	db	82
	db	101
	db	103
	db	105
	db	115
	db	116
	db	101
	db	114
	db	86
	db	97
	db	108
	db	117
	db	101
	db	115
	db	0
	db	0
	dd	0
	dd	0
	dd	0
@$xt$14RegisterValues	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@$xt$10std@locale	segment virtual
	align	2
@@$xt$10std@locale	label	byte
	dd	4
	dw	3
	dw	48
	dd	-1
	dd	3
	dw	60
	dw	64
	dd	0
	dw	0
	dw	0
	dd	0
	dd	1
	dd	1
	dd	@@std@locale@$bdtr$qv
	dw	1
	dw	68
	db	115
	db	116
	db	100
	db	58
	db	58
	db	108
	db	111
	db	99
	db	97
	db	108
	db	101
	db	0
	dd	0
	dd	0
	dd	0
@$xt$10std@locale	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@$xt$11_RWSTDMutex	segment virtual
	align	2
@@$xt$11_RWSTDMutex	label	byte
	dd	28
	dw	3
	dw	48
	dd	-1
	dd	3
	dw	60
	dw	64
	dd	0
	dw	0
	dw	0
	dd	0
	dd	1
	dd	1
	dd	@@_RWSTDMutex@$bdtr$qv
	dw	1
	dw	68
	db	95
	db	82
	db	87
	db	83
	db	84
	db	68
	db	77
	db	117
	db	116
	db	101
	db	120
	db	0
	dd	0
	dd	0
	dd	0
@$xt$11_RWSTDMutex	ends
_TEXT	ends
_DATA	segment dword public use32 'DATA'
@_$DCPKB$@std@locale@$bdtr$qv	segment virtual
	align	2
@@_$DCPKB$@std@locale@$bdtr$qv	label	dword
	dd	@@$xt$11_RWSTDGuard
	dd	4
	dd	-4
	dd	0
	dd	@@$xt$a2$p19__rwstd@ref_counted
	dd	20495
	dd	-12
	dd	0
@_$DCPKB$@std@locale@$bdtr$qv	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@_$ECTQKB$@std@locale@$bdtr$qv	segment virtual
	align	2
@@_$ECTQKB$@std@locale@$bdtr$qv	label	dword
	dd	0
	dd	-48
	dw	0
	dw	5
	dd	0
	dd	0
	dw	8
	dw	5
	dd	0
	dd	@@_$DCPKB$@std@locale@$bdtr$qv
	dw	20
	dw	5
	dd	0
	dd	0
	dw	8
	dw	5
	dd	0
	dd	@@_$DCPKB$@std@locale@$bdtr$qv+16
@_$ECTQKB$@std@locale@$bdtr$qv	ends
_DATA	ends
_TEXT	segment dword public use32 'CODE'
@std@locale@$bdtr$qv	segment virtual
	align	2
@@std@locale@$bdtr$qv	proc	near
?live16457@0:
@448:
	push      ebp
	mov       ebp,esp
	add       esp,-48
	mov       eax,offset @@_$ECTQKB$@std@locale@$bdtr$qv
	push      ebx
	push      esi
	push      edi
	mov       ebx,dword ptr [ebp+8]
	call      @__InitExceptBlockLDTC
	test      ebx,ebx
	je        @449
?live16457@16: ; EBX = this
	mov       edi,dword ptr [ebx]
	mov       word ptr [ebp-32],20
	lea       eax,dword ptr [edi+8]
	mov       edx,eax
	mov       dword ptr [ebp-4],edx
	mov       esi,edx
	cmp       dword ptr [esi+24],0
	jne       short @450
	push      esi
	call      @InitializeCriticalSection
	mov       dword ptr [esi+24],1
@450:
@451:
	push      esi
	call      @EnterCriticalSection
	inc       dword ptr [ebp-20]
	dec       dword ptr [edi+4]
	mov       esi,dword ptr [edi+4]
	dec       dword ptr [ebp-20]
	mov       eax,dword ptr [ebp-4]
	push      eax
	call      @LeaveCriticalSection
	mov       word ptr [ebp-32],8
	test      esi,esi
	jne       short @452
	mov       esi,edi
	mov       dword ptr [ebp-12],esi
	test      esi,esi
	je        short @453
	mov       eax,dword ptr [ebp-12]
	mov       edx,dword ptr [eax]
	mov       dword ptr [ebp-8],edx
	mov       word ptr [ebp-32],44
	push      3
	mov       ecx,dword ptr [ebp-12]
	push      ecx
	mov       eax,dword ptr [ecx]
	call      dword ptr [eax]
	mov       word ptr [ebp-32],8
	add       esp,8
@452:
@453:
	test      byte ptr [ebp+12],1
	je        short @456
	push      ebx
	call      @$bdele$qpv
	pop       ecx
?live16457@32: ; 
@456:
@449:
	mov       edx,dword ptr [ebp-48]
	mov       dword ptr fs:[0],edx
@457:
	pop       edi
	pop       esi
	pop       ebx
	mov       esp,ebp
	pop       ebp
	ret 
@@std@locale@$bdtr$qv	endp
@std@locale@$bdtr$qv	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@_RWSTDMutex@$bdtr$qv	segment virtual
	align	2
@@_RWSTDMutex@$bdtr$qv	proc	near
?live16458@0:
@458:
	push      ebp
	mov       ebp,esp
	push      ebx
	mov       ebx,dword ptr [ebp+8]
	test      ebx,ebx
	je        short @460
?live16458@16: ; EBX = this
	cmp       dword ptr [ebx+24],0
	je        short @462
	xor       eax,eax
	mov       dword ptr [ebx+24],eax
	push      ebx
	call      @DeleteCriticalSection
@462:
	test      byte ptr [ebp+12],1
	je        short @464
	push      ebx
	call      @$bdele$qpv
	pop       ecx
?live16458@64: ; 
@464:
@460:
@465:
	pop       ebx
	pop       ebp
	ret 
@@_RWSTDMutex@$bdtr$qv	endp
@_RWSTDMutex@$bdtr$qv	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@$xt$a2$p19__rwstd@ref_counted	segment virtual
	align	2
@@$xt$a2$p19__rwstd@ref_counted	label	dword
	dd	8
	dw	1024
	dw	16
	dd	@@$xt$p19__rwstd@ref_counted
	dd	2
	db	95
	db	95
	db	114
	db	119
	db	115
	db	116
	db	100
	db	58
	db	58
	db	114
	db	101
	db	102
	db	95
	db	99
	db	111
	db	117
	db	110
	db	116
	db	101
	db	100
	db	32
	db	42
	db	91
	db	50
	db	93
	db	0
@$xt$a2$p19__rwstd@ref_counted	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@$xt$11_RWSTDGuard	segment virtual
	align	2
@@$xt$11_RWSTDGuard	label	byte
	dd	4
	dw	3
	dw	48
	dd	-1
	dd	3
	dw	60
	dw	64
	dd	0
	dw	0
	dw	0
	dd	0
	dd	1
	dd	1
	dd	@@_RWSTDGuard@$bdtr$qv
	dw	1
	dw	68
	db	95
	db	82
	db	87
	db	83
	db	84
	db	68
	db	71
	db	117
	db	97
	db	114
	db	100
	db	0
	dd	0
	dd	0
	dd	0
@$xt$11_RWSTDGuard	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@_RWSTDGuard@$bdtr$qv	segment virtual
	align	2
@@_RWSTDGuard@$bdtr$qv	proc	near
?live16464@0:
@466:
	push      ebp
	mov       ebp,esp
	push      ebx
	mov       ebx,dword ptr [ebp+8]
	test      ebx,ebx
	je        short @467
	mov       eax,dword ptr [ebx]
	push      eax
	call      @LeaveCriticalSection
	test      byte ptr [ebp+12],1
	je        short @468
	push      ebx
	call      @$bdele$qpv
	pop       ecx
@468:
@467:
@469:
	pop       ebx
	pop       ebp
	ret 
@@_RWSTDGuard@$bdtr$qv	endp
@_RWSTDGuard@$bdtr$qv	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@$xt$p19__rwstd@ref_counted	segment virtual
	align	2
@@$xt$p19__rwstd@ref_counted	label	dword
	dd	4
	dw	16
	dw	12
	dd	@@$xt$19__rwstd@ref_counted
	db	95
	db	95
	db	114
	db	119
	db	115
	db	116
	db	100
	db	58
	db	58
	db	114
	db	101
	db	102
	db	95
	db	99
	db	111
	db	117
	db	110
	db	116
	db	101
	db	100
	db	32
	db	42
	db	0
@$xt$p19__rwstd@ref_counted	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@$xt$19__rwstd@ref_counted	segment virtual
	align	2
@@$xt$19__rwstd@ref_counted	label	byte
	dd	36
	dw	3
	dw	48
	dd	0
	dd	115
	dw	72
	dw	76
	dd	0
	dw	0
	dw	0
	dd	0
	dd	2
	dd	2
	dd	@@__rwstd@ref_counted@$bdtr$qv
	dw	1
	dw	80
	db	95
	db	95
	db	114
	db	119
	db	115
	db	116
	db	100
	db	58
	db	58
	db	114
	db	101
	db	102
	db	95
	db	99
	db	111
	db	117
	db	110
	db	116
	db	101
	db	100
	db	0
	db	0
	db	0
	db	0
	dd	0
	dd	0
	dd	@@$xt$11_RWSTDMutex
	dd	8
	dd	0
@$xt$19__rwstd@ref_counted	ends
_TEXT	ends
_DATA	segment dword public use32 'DATA'
@std@locale@numeric	segment virtual
	align	2
@@std@locale@numeric	label	dword
	dd	128
@std@locale@numeric	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@std@locale@__rw_ctype_category	segment virtual
	align	2
@@std@locale@__rw_ctype_category	label	dword
	dd	32
@std@locale@__rw_ctype_category	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@std@%ctype$c%@table_size	segment virtual
	align	2
@@std@%ctype$c%@table_size	label	dword
	dd	256
@std@%ctype$c%@table_size	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@std@%numeric_limits$i%@radix	segment virtual
	align	2
@@std@%numeric_limits$i%@radix	label	dword
	dd	2
@std@%numeric_limits$i%@radix	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@std@%numeric_limits$i%@is_modulo	segment virtual
@@std@%numeric_limits$i%@is_modulo	label	byte
	db	0
@std@%numeric_limits$i%@is_modulo	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@std@%numeric_limits$b%@is_signed	segment virtual
@@std@%numeric_limits$b%@is_signed	label	byte
	db	1
@std@%numeric_limits$b%@is_signed	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@std@%numeric_limits$c%@is_signed	segment virtual
@@std@%numeric_limits$c%@is_signed	label	byte
	db	1
@std@%numeric_limits$c%@is_signed	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
s@	label	byte
	;	s@+0:
	db	"0",0
	;	s@+2:
	db	" MHz",0
	;	s@+7:
	db	"Genuine Intel Celeron(TM) processor",0
	;	s@+43:
	db	"Genuine Intel Pentium(R) III processor",0
	;	s@+82:
	db	"Genuine Intel Pentium(R) III Xeon(TM) processor",0
	;	s@+130:
	db	"Genuine Intel Pentium(R) 4 processor",0
	;	s@+167:
	db	"Intel486(TM) DX processor",0
	;	s@+193:
	db	"Intel486(TM) SX processor",0
	;	s@+219:
	db	"IntelDX2(TM) processor",0
	;	s@+242:
	db	"Intel486(TM) processor",0
	;	s@+265:
	db	"IntelSX2(TM) processor",0
	;	s@+288:
	db	"Writeback Enhanced IntelDX2(TM) processor",0
	;	s@+330:
	db	"IntelDX4(TM) processor",0
	;	s@+353:
	db	"Intel 486 processor",0
	;	s@+373:
	db	"Intel Pentium(R) processor",0
	;	s@+400:
	db	"Intel Pentium(R) Pro processor",0
	;	s@+431:
	db	"Intel Pentium(R) II processor, model 3",0
	;	s@+470:
	db	"Intel Celeron(TM) processor, model 5",0
	;	s@+507:
	db	"Intel Pentium(R) II Xeon(TM) processor",0
	;	s@+546:
	db	"Intel Pentium(R) III Xeon(TM) processor",0
	;	s@+586:
	db	"Intel Pentium(R) II processor, model 5",0
	;	s@+625:
	db	"Intel Pentium(R) III processor",0
	;	s@+656:
	db	"Intel Celeron(TM) processor, model 6",0
	;	s@+693:
	db	"Intel Pentium(R) III Coppermine processor",0
	;	s@+735:
	db	"Unknown Genuine Intel processor",0
	;	s@+767:
	db	" with MMX",0
	align	4
_DATA	ends
_TEXT	segment dword public use32 'CODE'
_TEXT	ends
 extrn   __Exception_list:dword
 ?debug  C A002001240437075496E666F4024626374722471786F000000
@@CpuStats@$bctr$qv equ @CpuStats@$bctr$qv
 extrn   @CpuStats@$bctr$qv:near
@@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref equ @std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref
 extrn   @std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__nullref:byte
@InterlockedIncrement equ InterlockedIncrement
 extrn   InterlockedIncrement:near
@@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$basg$qpxc equ @std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$basg$qpxc
 extrn   @std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$basg$qpxc:near
 extrn   @__InitExceptBlockLDTC:near
 ?debug  C A002001A40437075496E666F4024626374722471727837437075496E666F000000
 ?debug  C A002001A40437075496E666F4024626173672471727837437075496E666F000000
 ?debug  C A002001140437075496E666F402462647472247176000000
@InterlockedDecrement equ InterlockedDecrement
 extrn   InterlockedDecrement:near
 extrn   @$bdele$qpv:near
@@CpuStats@$bdtr$qv equ @CpuStats@$bdtr$qv
 extrn   @CpuStats@$bdtr$qv:near
 ?debug  C A002001C40437075496E666F4064657465726D696E65437075496E666F247176000000
@GetSystemInfo equ GetSystemInfo
 extrn   GetSystemInfo:near
@@std@%basic_ostringstream$c19std@%char_traits$c%17std@%allocator$c%%@$bctr$qi equ @std@%basic_ostringstream$c19std@%char_traits$c%17std@%allocator$c%%@$bctr$qi
 extrn   @std@%basic_ostringstream$c19std@%char_traits$c%17std@%allocator$c%%@$bctr$qi:near
@@std@%basic_ostream$c19std@%char_traits$c%%@$blsh$qpqr42std@%basic_ostream$c19std@%char_traits$c%%$r42std@%basic_ostream$c19std@%char_traits$c%% equ @std@%basic_ostream$c19std@%char_traits$c%%@$blsh$qpqr42std@%basic_ostream$c19std@%char_traits$c%%$r42std@%basic_ostream$c19std@%char_traits$c%%
 extrn   @std@%basic_ostream$c19std@%char_traits$c%%@$blsh$qpqr42std@%basic_ostream$c19std@%char_traits$c%%$r42std@%basic_ostream$c19std@%char_traits$c%%:near
@@std@%basic_ostream$c19std@%char_traits$c%%@$blsh$qul equ @std@%basic_ostream$c19std@%char_traits$c%%@$blsh$qul
 extrn   @std@%basic_ostream$c19std@%char_traits$c%%@$blsh$qul:near
@@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$basg$qrx60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%% equ @std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$basg$qrx60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%
 extrn   @std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$basg$qrx60std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%:near
@@std@%basic_ostringstream$c19std@%char_traits$c%17std@%allocator$c%%@str$xqv equ @std@%basic_ostringstream$c19std@%char_traits$c%17std@%allocator$c%%@str$xqv
 extrn   @std@%basic_ostringstream$c19std@%char_traits$c%17std@%allocator$c%%@str$xqv:near
@@std@%basic_ostringstream$c19std@%char_traits$c%17std@%allocator$c%%@$bdtr$qv equ @std@%basic_ostringstream$c19std@%char_traits$c%17std@%allocator$c%%@$bdtr$qv
 extrn   @std@%basic_ostringstream$c19std@%char_traits$c%17std@%allocator$c%%@$bdtr$qv:near
@@std@%basic_ostream$c19std@%char_traits$c%%@put$qc equ @std@%basic_ostream$c19std@%char_traits$c%%@put$qc
 extrn   @std@%basic_ostream$c19std@%char_traits$c%%@put$qc:near
 ?debug  C A002001D40437075496E666F4064657465726D696E654370755370656564247176000000
@GetPriorityClass equ GetPriorityClass
 extrn   GetPriorityClass:near
@GetCurrentProcess equ GetCurrentProcess
 extrn   GetCurrentProcess:near
@SetPriorityClass equ SetPriorityClass
 extrn   SetPriorityClass:near
@@std@$blsh$qr42std@%basic_ostream$c19std@%char_traits$c%%pxc$r42std@%basic_ostream$c19std@%char_traits$c%% equ @std@$blsh$qr42std@%basic_ostream$c19std@%char_traits$c%%pxc$r42std@%basic_ostream$c19std@%char_traits$c%%
 extrn   @std@$blsh$qr42std@%basic_ostream$c19std@%char_traits$c%%pxc$r42std@%basic_ostream$c19std@%char_traits$c%%:near
 ?debug  C A002001B40437075496E666F4061737369676E2471727837437075496E666F000000
@@CpuStats@$basg$qrx8CpuStats equ @CpuStats@$basg$qrx8CpuStats
 extrn   @CpuStats@$basg$qrx8CpuStats:near
 ?debug  C A002001E40437075496E666F4064657465726D696E65437075537461747324717573000000
 ?debug  C A002001A40437075496E666F4064657465726D696E654370754964247176000000
 ?debug  C A002002140437075496E666F4064657465726D696E65486967686573744370754964247176000000
@@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$bctr$qpxcrx17std@%allocator$c% equ @std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$bctr$qpxcrx17std@%allocator$c%
 extrn   @std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@$bctr$qpxcrx17std@%allocator$c%:near
 ?debug  C A002002640437075496E666F4064657465726D696E654370754964656E74696669636174696F6E247176000000
 ?debug  C A002002B40437075496E666F4064657465726D696E654C617267657374457874656E64656446656174757265247176000000
 ?debug  C A002002440437075496E666F4064657465726D696E65457874656E64656446656174757265247176000000
 ?debug  C A002001F40437075496E666F4064657465726D696E654E616D65537472696E67247176000000
 ?debug  C A002002340437075496E666F4064657465726D696E65416D644C314361636865496E666F247176000000
 ?debug  C A002002340437075496E666F4064657465726D696E65416D644C324361636865496E666F247176000000
 ?debug  C A002002340437075496E666F4064657465726D696E65496E74656C4361636865496E666F247176000000
 ?debug  C A002002140437075496E666F4064657465726D696E654F6C64496E74656C4E616D65247176000000
@_strlen equ _strlen
 extrn   _strlen:near
@@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@replace$quiuipxcuiuiui equ @std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@replace$quiuipxcuiuiui
 extrn   @std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@replace$quiuipxcuiuiui:near
 ?debug  C A002002940437075496E666F4064657465726D696E6543656C65726F6E416E6458656F6E2471756C706F74326F000000
 ?debug  C A002001E40437075496E666F4063616C63756C617465437075537065656424787176000000
@timeGetTime equ timeGetTime
 extrn   timeGetTime:near
 ?debug  C A002001F40437075496E666F4064657465726D696E6554696D655374616D7024787176000000
@@std@%basic_stringbuf$c19std@%char_traits$c%17std@%allocator$c%%@$bdtr$qv equ @std@%basic_stringbuf$c19std@%char_traits$c%17std@%allocator$c%%@$bdtr$qv
 extrn   @std@%basic_stringbuf$c19std@%char_traits$c%17std@%allocator$c%%@$bdtr$qv:near
@@std@%basic_ios$c19std@%char_traits$c%%@$bdtr$qv equ @std@%basic_ios$c19std@%char_traits$c%%@$bdtr$qv
 extrn   @std@%basic_ios$c19std@%char_traits$c%%@$bdtr$qv:near
@@std@%basic_ostream$c19std@%char_traits$c%%@$bdtr$qv equ @std@%basic_ostream$c19std@%char_traits$c%%@$bdtr$qv
 extrn   @std@%basic_ostream$c19std@%char_traits$c%%@$bdtr$qv:near
@@std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__getRep$quiui equ @std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__getRep$quiui
 extrn   @std@%basic_string$c19std@%char_traits$c%17std@%allocator$c%%@__getRep$quiui:near
@_memcpy equ _memcpy
 extrn   _memcpy:near
@_atol equ _atol
 extrn   _atol:near
@@CpuStats@$bctr$qrx8CpuStats equ @CpuStats@$bctr$qrx8CpuStats
 extrn   @CpuStats@$bctr$qrx8CpuStats:near
@@std@ios_base@$bdtr$qv equ @std@ios_base@$bdtr$qv
 extrn   @std@ios_base@$bdtr$qv:near
@@std@%basic_streambuf$c19std@%char_traits$c%%@$bdtr$qv equ @std@%basic_streambuf$c19std@%char_traits$c%%@$bdtr$qv
 extrn   @std@%basic_streambuf$c19std@%char_traits$c%%@$bdtr$qv:near
@@RegisterValues@$bdtr$qv equ @RegisterValues@$bdtr$qv
 extrn   @RegisterValues@$bdtr$qv:near
@InitializeCriticalSection equ InitializeCriticalSection
 extrn   InitializeCriticalSection:near
@EnterCriticalSection equ EnterCriticalSection
 extrn   EnterCriticalSection:near
@LeaveCriticalSection equ LeaveCriticalSection
 extrn   LeaveCriticalSection:near
@DeleteCriticalSection equ DeleteCriticalSection
 extrn   DeleteCriticalSection:near
@@__rwstd@ref_counted@$bdtr$qv equ @__rwstd@ref_counted@$bdtr$qv
 extrn   @__rwstd@ref_counted@$bdtr$qv:near
 ?debug  C 9F77696E6D6D2E6C6962
 ?debug  C 9F757569642E6C6962
 ?debug  C 9F757569642E6C6962
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\ostream.h" 10503 10272
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\istream.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\rw/usefacet.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\rw/codecvt.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\rw/numbrw.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\rw/rwlocale.cc" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\float.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\cfloat.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\rw/..\math.h" 10503 10272
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\rw/math.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\limits.stl" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\limits.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\rw/iosbase.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\rw/numeral.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\rw/ctype.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\rw/vendor.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\rw/locvecto.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\rw/locimpl.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\typeinfo.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\time.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\ctime.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\rw/rwlocale.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\ios.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\streambu.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\sstream.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\errno.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\dos.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\stdexcep.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\iosfwd.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\rw/iotraits.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\_nfile.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\stdio.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\cstdio.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\rw/traits.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\rw/stdmutex.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\utility.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\rw/iterator.cc" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\rw/iterator.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\alloc.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\except.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\exceptio.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\new.h" 10503 10272
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\_lim.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\climits.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\cstdlib.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\memory.stl" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\memory.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\rw/string_r.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\wctype.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\cwctype.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\mbstring.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\tchar.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\wchar.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\cwchar.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\cctype.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\cstring.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\rw/stdwind.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\stddef.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\cstddef.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\rw/stddefs.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\rw/rwstderr.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\compnent.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\stdcomp.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\string.stl" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\imm.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\mcx.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\winsvc.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\commdlg.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\oleauto.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\propidl.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\oaidl.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\msxml.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\servprov.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\oleidl.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\urlmon.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\cguid.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\objidl.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\unknwn.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\search.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\stdlib.h" 10503 10272
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\objbase.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\ole2.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\prsht.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\winspool.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\winsmcrd.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\winioctl.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\rpcnsip.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\rpcndr.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\wtypes.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\winscard.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\winefs.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\wincrypt.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\qos.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\winsock2.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\winperf.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\shellapi.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\rpcasync.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\rpcnterr.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\rpcnsi.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\rpcdcep.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\rpcdce.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\rpc.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\nb30.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\mmsystem.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\lzexpand.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\dlgs.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\ddeml.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\dde.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\cderr.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\winnetwk.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\winreg.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\winver.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\wincon.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\winnls.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\tvout.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\winuser.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\pshpack1.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\wingdi.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\winerror.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\winbase.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\pshpack8.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\pshpack2.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\poppack.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\pshpack4.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\_loc.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\locale.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\_str.h" 10503 10272
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\string.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\guiddef.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\basetsd.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\mbctype.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\ctype.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\winnt.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\windef.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\stdarg.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\excpt.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\_null.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\_defs.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\_stddef.h" 10303 10240
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\mem.h" 10503 10272
	?debug	D "D:\PROGRAMMI\BORLAND\CBUILDER5\INCLUDE\windows.h" 10303 10240
	?debug	D "..\RegisterValues.h" 10940 4123
	?debug	D "..\CpuFeatures.h" 10940 3914
	?debug	D "..\CpuStats.h" 10940 2320
	?debug	D "..\SysInfoClasses.h" 11452 42008
	?debug	D "..\CpuInfo.h" 11452 41068
	?debug	D "..\CpuInfo.cpp" 11452 41883
	end
