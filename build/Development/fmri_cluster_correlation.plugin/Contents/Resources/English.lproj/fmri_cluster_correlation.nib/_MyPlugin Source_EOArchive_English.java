// _«PROJECTNAMEASIDENTIFIER» Source_EOArchive_English.java
// Generated by EnterpriseObjects palette at Tuesday, September 21, 2004 10:06:28 PM US/Eastern

import com.webobjects.eoapplication.*;
import com.webobjects.eocontrol.*;
import com.webobjects.eointerface.*;
import com.webobjects.eointerface.swing.*;
import com.webobjects.foundation.*;
import java.awt.*;
import javax.swing.*;
import javax.swing.border.*;
import javax.swing.table.*;
import javax.swing.text.*;

public class _«PROJECTNAMEASIDENTIFIER» Source_EOArchive_English extends com.webobjects.eoapplication.EOArchive {
    com.webobjects.eointerface.swing.EOFrame _eoFrame0;
    com.webobjects.eointerface.swing.EOTextField _nsTextField0;
    javax.swing.JButton _nsButton0, _nsButton1, _nsButton2;
    javax.swing.JPanel _nsView0;

    public _«PROJECTNAMEASIDENTIFIER» Source_EOArchive_English(Object owner, NSDisposableRegistry registry) {
        super(owner, registry);
    }

    protected void _construct() {
        Object owner = _owner();
        EOArchive._ObjectInstantiationDelegate delegate = (owner instanceof EOArchive._ObjectInstantiationDelegate) ? (EOArchive._ObjectInstantiationDelegate)owner : null;
        Object replacement;

        super._construct();

        _nsTextField0 = (com.webobjects.eointerface.swing.EOTextField)_registered(new com.webobjects.eointerface.swing.EOTextField(), "NSTextField2");
        _nsButton2 = (javax.swing.JButton)_registered(new javax.swing.JButton(""), "NSButton5");
        _nsButton1 = (javax.swing.JButton)_registered(new javax.swing.JButton("Cancel"), "NSButton1");
        _nsButton0 = (javax.swing.JButton)_registered(new javax.swing.JButton("OK"), "NSButton");

        if ((delegate != null) && ((replacement = delegate.objectForOutletPath(this, "pluginSheet")) != null)) {
            _eoFrame0 = (replacement == EOArchive._ObjectInstantiationDelegate.NullObject) ? null : (com.webobjects.eointerface.swing.EOFrame)replacement;
            _replacedObjects.setObjectForKey(replacement, "_eoFrame0");
        } else {
            _eoFrame0 = (com.webobjects.eointerface.swing.EOFrame)_registered(new com.webobjects.eointerface.swing.EOFrame(), "Panel");
        }

        _nsView0 = (JPanel)_eoFrame0.getContentPane();
    }

    protected void _awaken() {
        super._awaken();
        _nsButton2.addActionListener((com.webobjects.eointerface.swing.EOControlActionAdapter)_registered(new com.webobjects.eointerface.swing.EOControlActionAdapter(_owner(), "showPluginHelp", _nsButton2), ""));
        _nsButton1.addActionListener((com.webobjects.eointerface.swing.EOControlActionAdapter)_registered(new com.webobjects.eointerface.swing.EOControlActionAdapter(_owner(), "abortInteractiveSetup", _nsButton1), ""));

        if (_replacedObjects.objectForKey("_eoFrame0") == null) {
            _connect(_owner(), _eoFrame0, "pluginSheet");
        }

        _nsButton0.addActionListener((com.webobjects.eointerface.swing.EOControlActionAdapter)_registered(new com.webobjects.eointerface.swing.EOControlActionAdapter(_owner(), "doInteractiveProcessing", _nsButton0), ""));
    }

    protected void _init() {
        super._init();
        _setFontForComponent(_nsTextField0, "Lucida Grande", 13, Font.PLAIN);
        _nsTextField0.setEditable(false);
        _nsTextField0.setOpaque(false);
        _nsTextField0.setText("Plugin Interface Here!");
        _nsTextField0.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        _nsTextField0.setSelectable(false);
        _nsTextField0.setEnabled(true);
        _nsTextField0.setBorder(null);
        _setFontForComponent(_nsButton2, "Lucida Grande", 13, Font.PLAIN);
        _nsButton2.setMargin(new Insets(0, 2, 0, 2));
        _setFontForComponent(_nsButton1, "Lucida Grande", 13, Font.PLAIN);
        _nsButton1.setMargin(new Insets(0, 2, 0, 2));
        _setFontForComponent(_nsButton0, "Lucida Grande", 13, Font.PLAIN);
        _nsButton0.setMargin(new Insets(0, 2, 0, 2));
        if (!(_nsView0.getLayout() instanceof EOViewLayout)) { _nsView0.setLayout(new EOViewLayout()); }
        _nsButton0.setSize(71, 26);
        _nsButton0.setLocation(372, 271);
        ((EOViewLayout)_nsView0.getLayout()).setAutosizingMask(_nsButton0, EOViewLayout.MinXMargin | EOViewLayout.MinYMargin);
        _nsView0.add(_nsButton0);
        _nsButton1.setSize(75, 26);
        _nsButton1.setLocation(290, 271);
        ((EOViewLayout)_nsView0.getLayout()).setAutosizingMask(_nsButton1, EOViewLayout.MinXMargin | EOViewLayout.MinYMargin);
        _nsView0.add(_nsButton1);
        _nsButton2.setSize(25, 24);
        _nsButton2.setLocation(13, 272);
        ((EOViewLayout)_nsView0.getLayout()).setAutosizingMask(_nsButton2, EOViewLayout.MaxXMargin | EOViewLayout.MinYMargin);
        _nsView0.add(_nsButton2);
        _nsTextField0.setSize(147, 17);
        _nsTextField0.setLocation(148, 131);
        ((EOViewLayout)_nsView0.getLayout()).setAutosizingMask(_nsTextField0, EOViewLayout.MinXMargin | EOViewLayout.MaxXMargin | EOViewLayout.MaxYMargin | EOViewLayout.MinYMargin);
        _nsView0.add(_nsTextField0);

        if (_replacedObjects.objectForKey("_eoFrame0") == null) {
            _nsView0.setSize(452, 307);
            _eoFrame0.setTitle("Panel");
            _eoFrame0.setLocation(291, 286);
            _eoFrame0.setSize(452, 307);
        }
    }
}
