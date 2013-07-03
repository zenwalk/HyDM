﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using DevExpress.XtraEditors;
using DevExpress.XtraTreeList.Nodes;

namespace Hy.Dictionary.UI
{
    public partial class FrmDictionary : DevExpress.XtraEditors.XtraForm
    {
        public FrmDictionary()
        {
            InitializeComponent();
        }

        private TreeListNode m_NodeRoot;
        public void Init()
        {
            tlDictionary.ClearNodes();

            m_NodeRoot = tlDictionary.AppendNode(new object[] { "所有字典项", null }, null);

            IList<DictItem> diRootList = DictHelper.GetRootTypeList();
            foreach (DictItem di in diRootList)
            {
                BoundDictItem(di, m_NodeRoot);
            }
        }

        private void BoundDictItem(DictItem dictItem,TreeListNode nodeParent)
        {
            if (dictItem == null)
                return;

            TreeListNode nodeItem= tlDictionary.AppendNode(new object[] { dictItem.Name, dictItem.Code }, nodeParent, dictItem);
            if (dictItem.SubItems != null)
            {
                foreach (DictItem diSub in dictItem.SubItems)
                {
                    BoundDictItem(diSub, nodeItem);
                }
            }
        }

        private void barButtonItem1_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            Init();
        }

        private void barButtonItem4_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            SendMessage("正在保存..");
            m_SaveIndex = 0;
            foreach (TreeListNode nodeItem in m_NodeRoot.Nodes)
            {
                SaveNode(m_NodeRoot);
            }
            SendMessage(string.Format("保存成功，共{0}个命令", m_SaveIndex));

            Init();
        }
        private int m_SaveIndex = 0;
        private void SendMessage(string strMsg)
        {
            this.lblStatus.Caption = strMsg;
            Application.DoEvents();
        }
        private void SaveNode(TreeListNode nodeItem)
        {
            SendMessage(string.Format("正在保存第{0}个命令...", ++m_SaveIndex));
            DictItem dItem = CollectItem(nodeItem);
            if (dItem != null)
                DictHelper.SaveItem(dItem);

            foreach (TreeListNode nodeSub in nodeItem.Nodes)
            {
                SaveNode(nodeSub);
            }
        }

        private DictItem CollectItem(TreeListNode nodeItem)
        {
            if(nodeItem ==null)
                return null;

            DictItem dItem = nodeItem.Tag as DictItem;
            if (dItem==null)
            {
                dItem=new DictItem();
            }
            dItem.Name=nodeItem.GetValue(tlColName) as string;
            dItem.Code=nodeItem.GetValue(tlColCode) as string;
            dItem.Parent = nodeItem.ParentNode == null ? null : nodeItem.ParentNode.Tag as DictItem;

            return dItem;
        }

        private void barBtnAdd_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            if (tlDictionary.FocusedNode == null)
                return;

            tlDictionary.AppendNode(new object[] { "新名称", "新编码" }, tlDictionary.FocusedNode);
        }

        private void barBtnDelete_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            DictItem dItem = tlDictionary.FocusedNode.Tag as DictItem;
            if (dItem != null)
                DictHelper.DeleteItem(dItem);
        }

        private void tlDictionary_FocusedNodeChanged(object sender, DevExpress.XtraTreeList.FocusedNodeChangedEventArgs e)
        {
            barBtnAdd.Enabled = (e.Node != null);
            barBtnDelete.Enabled = (e.Node != null && e.Node != m_NodeRoot);
        }
    }
}