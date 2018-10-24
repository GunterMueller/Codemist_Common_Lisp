;; Set up the autoload properties for CCL.  This uses some functions in
;; util.lisp
;;
;; Mike Dewar 15/9/95

(in-package "BOOT")

(setq nagbr-files '(nag-c02 nag-c05 nag-c06 nag-d01 nag-d02 nag-d03 
                    nag-e01 nag-e02 nag-e04 nag-f01 nag-f02 nag-f04 
                    nag-f07 nag-s nag-e02a) )

(setq asauto-files '(ax) )

;; Function lists defined in util.lisp
(|setBootAutloadProperties| comp-functions '(oldcomp) )
(|setBootAutloadProperties| parse-functions '(metaparser) )
(|setBootAutloadProperties| browse-functions '(browser) )
;;These are now in 'browser'
;;(|setBootAutloadProperties| basic-commands-functions '(basiccom) )
(|setBootAutloadProperties| translate-functions '(translator) )
(|setNAGBootAutloadProperties| nagbr-functions nagbr-files )
(|setBootAutloadProperties| asauto-functions asauto-files)
(|setBootAutloadProperties| anna-functions '(anna))

